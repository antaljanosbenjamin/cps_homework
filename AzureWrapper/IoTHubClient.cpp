//
// Created by kovi on 12/6/17.
//


#include <thread>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "azure_c_shared_utility/platform.h"
#include "azure_c_shared_utility/threadapi.h"
#include "azure_c_shared_utility/crt_abstractions.h"
#include "azure_c_shared_utility/shared_util_options.h"
#include "iothub_client.h"
#include "iothub_client_options.h"
#include "iothub_message.h"
#include "iothubtransportamqp.h"

#include <rapidjson/prettywriter.h> // for stringify JSON

#include "AzureWrapper/IoTHubClient.hpp"


using namespace std::chrono_literals;
using namespace rapidjson;
using namespace boost::posix_time;

#define EXPAND(CLASS, FUNCTION) CLASS##_##FUNCTION
#define IHC(FUNCTION) EXPAND(IoTHubClient_LL,FUNCTION)
#define IHM(FUNCTION) EXPAND(IoTHubMessage,FUNCTION)

std::mutex IoTHubClient::globalMutex;
std::map<EventInstance *, IoTHubClient *> IoTHubClient::eventInstanceMapping;
std::set<IoTHubClient *> IoTHubClient::livingClients;
bool IoTHubClient::initialized = false;

void IoTHubClient::init() {
    std::lock_guard<std::mutex> globalLock(globalMutex);
    initWithoutLock();
}

void IoTHubClient::initWithoutLock() {
    if (initialized) {
        BOOST_LOG_TRIVIAL(debug) << "Already initialized...";
        return;
    }
    BOOST_LOG_TRIVIAL(debug) << "Init...";
    if (platform_init()) {
        BOOST_LOG_TRIVIAL(error) << "Failed to initialize the platform!";
        throw std::runtime_error("Failed to initialize the platform!");
    }
    initialized = true;
}

void IoTHubClient::finalize() {
    std::lock_guard<std::mutex> globalLock(globalMutex);
    finalizeWithoutLock();
}

void IoTHubClient::finalizeWithoutLock() {
    if (!initialized) {
        BOOST_LOG_TRIVIAL(debug) << "Already finalized...";
        return;
    }
    if (livingClients.size() != 0) {
        BOOST_LOG_TRIVIAL(error) << "There are living clients...";
    }
    BOOST_LOG_TRIVIAL(debug) << "Finalize...";
    platform_deinit();
    initialized = false;
}

IoTHubClient::IoTHubClient(const std::string &connectionString,
                           std::function<void(const rapidjson::Document &)> receivedMessageConsumer, bool trace,
                           uint32_t keepAlive)
        : connectionString(connectionString),
          receivedMessageConsumer(receivedMessageConsumer),
          trace(trace),
          keepAlive(keepAlive),
          clientHandle(nullptr),
          ownMutex(),
          canRun(true),
          workerThread(),
          notConfirmedIntances(),
          nextTrackingId(0) {


    std::lock_guard<std::mutex> globalLock(globalMutex);
    initWithoutLock();

    this->clientHandle = IoTHubClient_LL_CreateFromConnectionString(connectionString.c_str(), AMQP_Protocol);
    if (this->clientHandle != nullptr) {
        IHC(SetOption)(clientHandle, OPTION_LOG_TRACE, &this->trace);
        IHC(SetOption)(clientHandle, OPTION_C2D_KEEP_ALIVE_FREQ_SECS, &this->keepAlive);

        if (IHC(SetMessageCallback)(this->clientHandle, receiveMessage, this) !=
            IOTHUB_CLIENT_OK) {
            BOOST_LOG_TRIVIAL(error) << "IoTHubClient_SetMessageCallback........FAILED!";
            throw std::runtime_error("IoTHubClient_SetMessageCallback........FAILED!");
        }

        BOOST_LOG_TRIVIAL(debug) << "Init successful!";

    } else {
        BOOST_LOG_TRIVIAL(error) << "IoTHubClient_LL_CreateFromConnectionString........FAILED!";
        throw std::runtime_error("IoTHubClient_LL_CreateFromConnectionString........FAILED!");
    }
}

void IoTHubClient::start() {
    this->canRun.store(true);
    this->workerThread = std::thread(&IoTHubClient::doWork, this);
    std::lock_guard<std::mutex> globalLock(globalMutex);
    livingClients.insert(this);
}

void IoTHubClient::stop() {
    this->stopWorkerThread();
    std::lock_guard<std::mutex> globalLock(globalMutex);
    livingClients.erase(this);
}

void IoTHubClient::stopWorkerThread() {
    this->canRun.store(false);
    if (this->workerThread.joinable()) {
        this->workerThread.join();
    }
}

IoTHubClient::~IoTHubClient() {
    this->stopWorkerThread();
    std::lock_guard<std::mutex> globalLock(globalMutex);

    std::for_each(notConfirmedIntances.begin(), notConfirmedIntances.end(),
                  [&](EventInstance *eventInstance) { eventInstanceMapping.erase(eventInstance); });


    IoTHubClient_LL_Destroy(this->clientHandle);

    if (livingClients.size() == 0) {
        finalizeWithoutLock();
    }
}

IOTHUBMESSAGE_DISPOSITION_RESULT
IoTHubClient::receiveMessage(IOTHUB_MESSAGE_HANDLE message, void *userContextCallback) {
    IoTHubClient *client = (IoTHubClient *) userContextCallback;
    const unsigned char *buffer = NULL;
    size_t size = 0;

    // Message content
    IOTHUBMESSAGE_CONTENT_TYPE contentType = IoTHubMessage_GetContentType(message);

    if (contentType == IOTHUBMESSAGE_BYTEARRAY) {
        if (IoTHubMessage_GetByteArray(message, &buffer, &size) == IOTHUB_MESSAGE_OK) {
            std::string messageStr(buffer, buffer + size);
            BOOST_LOG_TRIVIAL(debug) << "Message received: " << messageStr << ".";

            rapidjson::Document message;
            if (message.Parse(messageStr.c_str()).HasParseError()) {
                BOOST_LOG_TRIVIAL(error) << "Error during parsing message: " << messageStr << ".";
                return IOTHUBMESSAGE_ACCEPTED;
            }
            {
                std::lock_guard<std::mutex> globalLock(globalMutex);
                if (livingClients.find(client) == livingClients.end()) {
                    BOOST_LOG_TRIVIAL(error) << "Can't find client!";
                    return IOTHUBMESSAGE_REJECTED;
                }
                client->receive(message);
            }

        } else {
            BOOST_LOG_TRIVIAL(error) << "Failed getting the BINARY body of the message received.";
            return IOTHUBMESSAGE_ACCEPTED;
        }
    } else {
        BOOST_LOG_TRIVIAL(error) << "Failed getting the body of the message received (type " << contentType << ")";
    }
    return IOTHUBMESSAGE_ACCEPTED;
}

void IoTHubClient::confirmationCallback(IOTHUB_CLIENT_CONFIRMATION_RESULT result, void *userContextCallback) {
    EventInstance *eventInstance = (EventInstance *) userContextCallback;

    BOOST_LOG_TRIVIAL(debug) << "Message confirmation received for message " << eventInstance->messageTrackingId
                             << "! Status is " << ENUM_TO_STRING(IOTHUB_CLIENT_CONFIRMATION_RESULT, result);

    {
        std::lock_guard<std::mutex> globalLock(globalMutex);
        auto it = eventInstanceMapping.find(eventInstance);
        if (it == eventInstanceMapping.end()) {
            BOOST_LOG_TRIVIAL(error) << "Can't find client!";
            return;
        }
        it->second->removeFromNotConfirmedIntances(eventInstance);
        BOOST_LOG_TRIVIAL(debug) << "Message " << eventInstance->messageTrackingId << " is removed.";
    }

    IoTHubMessage_Destroy(eventInstance->messageHandle);
    delete eventInstance;
}


void IoTHubClient::doWork() {

    while (canRun.load()) {
        BOOST_LOG_TRIVIAL(debug) << "Do some work...";
        IoTHubClient_LL_DoWork(this->clientHandle);
        std::this_thread::sleep_for(1s);
    }

    size_t notConfirmedInstanceCount;
    {
        std::lock_guard<std::mutex> ownLock(this->ownMutex);
        notConfirmedInstanceCount = notConfirmedIntances.size();
    }
    size_t remainingConfirmation = notConfirmedInstanceCount;
    size_t trialCount = 0;
    BOOST_LOG_TRIVIAL(debug) << "Stopping IoTHubClient...";
    // best effort to send all message
    while (trialCount < notConfirmedInstanceCount * 10 && remainingConfirmation > 0) {
        BOOST_LOG_TRIVIAL(debug) << "Do some more work..." << remainingConfirmation;
        IHC(DoWork)(this->clientHandle);
        {
            std::lock_guard<std::mutex> ownLock(this->ownMutex);
            remainingConfirmation = notConfirmedIntances.size();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void IoTHubClient::addToEventInstanceMapping(EventInstance *eventInstance) {
    std::lock_guard<std::mutex> globalLock(globalMutex);
    eventInstanceMapping.emplace(eventInstance, this);
}

void IoTHubClient::removeFromEventInstanceMapping(EventInstance *eventInstance) {
    std::lock_guard<std::mutex> globalLock(globalMutex);
    eventInstanceMapping.erase(eventInstance);
}

void IoTHubClient::addToNotConfirmedIntances(EventInstance *eventInstance) {
    std::lock_guard<std::mutex> ownLock(this->ownMutex);
    notConfirmedIntances.insert(eventInstance);
}

void IoTHubClient::removeFromNotConfirmedIntances(EventInstance *eventInstance) {
    std::lock_guard<std::mutex> ownLock(this->ownMutex);
    notConfirmedIntances.erase(eventInstance);
}

void IoTHubClient::sendMessage(const rapidjson::Document &message) {

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    message.Accept(writer);

    std::string messageStr = buffer.GetString();
    auto *eventInstance = new EventInstance{};
    if ((eventInstance->messageHandle = IoTHubMessage_CreateFromByteArray(
            (const unsigned char *) messageStr.c_str(), messageStr.size())) == NULL) {
        BOOST_LOG_TRIVIAL(error) << "iotHubMessageHandle is NULL!";
    } else {
        eventInstance->messageTrackingId = this->nextTrackingId++;

        MAP_HANDLE propMap = IHM(Properties)(eventInstance->messageHandle);
        std::stringstream propStream;
        propStream << "PropMsg_" << eventInstance->messageTrackingId;
        std::string propText = propStream.str();

        if (Map_AddOrUpdate(propMap, "PropName", propText.c_str()) != MAP_OK) {
            BOOST_LOG_TRIVIAL(error) << "Map_AddOrUpdate Failed!";
        }

        // Setting messages with the same UUID values just for example.
        IHM(SetContentTypeSystemProperty)(eventInstance->messageHandle, "application/json");
        IHM(SetContentEncodingSystemProperty)(eventInstance->messageHandle, "utf-8");

        this->addToEventInstanceMapping(eventInstance);
        if (IHC(SendEventAsync)(this->clientHandle, eventInstance->messageHandle, confirmationCallback,
                                eventInstance) != IOTHUB_CLIENT_OK) {
            this->addToNotConfirmedIntances(eventInstance);
            BOOST_LOG_TRIVIAL(error) << "IoTHubClient_SendEventAsync........FAILED!";
            this->removeFromEventInstanceMapping(eventInstance);
        } else {
            BOOST_LOG_TRIVIAL(debug)
                << "IoTHubClient_SendEventAsync accepted data for transmission to IoT Hub. Message is: " << messageStr
                << ", tracking id is "
                << eventInstance->messageTrackingId << ".";
            this->addToNotConfirmedIntances(eventInstance);
        }
    }
}

void IoTHubClient::receive(const rapidjson::Document &message) {
    receivedMessageConsumer(message);
}