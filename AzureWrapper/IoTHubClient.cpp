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

void IoTHubClient::init(){
    BOOST_LOG_TRIVIAL(debug) << "Init....";
    if (platform_init()) {
        BOOST_LOG_TRIVIAL(error) << "Failed to initialize the platform!";
        throw std::runtime_error("Failed to initialize the platform!");
    }
}

void IoTHubClient::finalize(){
    platform_deinit();
}


IoTHubClient::IoTHubClient(const std::string &connectionString, bool trace, uint32_t keepAlive)
        : connectionString(connectionString),
          trace(trace),
          keepAlive(keepAlive),
          clientHandle(nullptr),
          initialized(false),
          ownMutex(),
          canRun(true),
          conditionVariable(),
          workerThread(),
          notConfirmedIntances() {



    this->clientHandle = IoTHubClient_LL_CreateFromConnectionString(connectionString.c_str(), AMQP_Protocol);
    if (this->clientHandle != nullptr) {
        IHC(SetOption)(clientHandle, OPTION_LOG_TRACE, &this->trace);
        IHC(SetOption)(clientHandle, OPTION_C2D_KEEP_ALIVE_FREQ_SECS, &this->keepAlive);

        if (IHC(SetMessageCallback)(this->clientHandle, receiveMessage, this) !=
            IOTHUB_CLIENT_OK) {
            BOOST_LOG_TRIVIAL(error) << "IoTHubClient_SetMessageCallback..........FAILED!";
            throw std::runtime_error("IoTHubClient_SetMessageCallback..........FAILED!");
        }
        this->workerThread = std::thread(&IoTHubClient::doWork, this);

        BOOST_LOG_TRIVIAL(debug) << "Init successful!";

        std::lock_guard<std::mutex> globalLock(globalMutex);
        livingClients.insert(this);
    } else {
        BOOST_LOG_TRIVIAL(error) << "IoTHubClient_LL_CreateFromConnectionString..........FAILED!";
        throw std::runtime_error("IoTHubClient_LL_CreateFromConnectionString..........FAILED!");
    }
}

IoTHubClient::~IoTHubClient() {
    this->canRun.store(false);
    this->workerThread.join();

    {
        std::lock_guard<std::mutex> globalLock(globalMutex);

        std::for_each(notConfirmedIntances.begin(), notConfirmedIntances.end(),
                      [&](EventInstance *eventInstance) {
                          eventInstanceMapping.erase(eventInstance);
                      });
        livingClients.erase(this);
    }

    IoTHubClient_LL_Destroy(this->clientHandle);
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
            std::string messageStr(buffer, buffer+size);
            BOOST_LOG_TRIVIAL(debug) << "Message received: " << messageStr << ".";

        } else {
            (void) printf("Failed getting the BINARY body of the message received.\r\n");
        }
    } else if (contentType == IOTHUBMESSAGE_STRING) {
        // TODO
    } else {
        (void) printf("Failed getting the body of the message received (type %i).\r\n", contentType);
    }

    /* Some device specific action code goes here... */
    return IOTHUBMESSAGE_ACCEPTED;
}

void IoTHubClient::confirmationCallback(IOTHUB_CLIENT_CONFIRMATION_RESULT result, void *userContextCallback) {
    EventInstance *eventInstance = (EventInstance *) userContextCallback;

    BOOST_LOG_TRIVIAL(debug) << "Message confirmation received for message " << eventInstance->messageTrackingId
                             << "! Status is " << ENUM_TO_STRING(IOTHUB_CLIENT_CONFIRMATION_RESULT, result);

    // TODO remove from messages and call member function


    IoTHubMessage_Destroy(eventInstance->messageHandle);
    delete eventInstance;
}


void IoTHubClient::doWork() {
    IOTHUB_CLIENT_STATUS status;

    while (canRun.load()) {
        BOOST_LOG_TRIVIAL(debug) << "Do some work....";
        IoTHubClient_LL_DoWork(this->clientHandle);
        std::this_thread::sleep_for(1s);
    }

    // best effort to send all message
    for (int i = 0; i < notConfirmedIntances.size() * 2; i++) {
        IHC(DoWork)(this->clientHandle);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    {
        std::unique_lock<std::mutex> lock(ownMutex);
        this->conditionVariable.wait_for(lock, 5s, [&]() { return notConfirmedIntances.size() == 0; });
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
    std::lock_guard<std::mutex> globalLock(this->ownMutex);
    notConfirmedIntances.insert(eventInstance);
}

void IoTHubClient::removeFromNotConfirmedIntances(EventInstance *eventInstance) {
    std::lock_guard<std::mutex> globalLock(this->ownMutex);
    eventInstanceMapping.erase(eventInstance);
}

void IoTHubClient::sendMessage(const rapidjson::Document &message) {

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    message.Accept(writer);

    std::string messageStr = buffer.GetString();
    EventInstance *eventInstance = new EventInstance{};
    if ((eventInstance->messageHandle = IoTHubMessage_CreateFromByteArray(
            (const unsigned char *) messageStr.c_str(), messageStr.size())) == NULL) {
        BOOST_LOG_TRIVIAL(error) << "iotHubMessageHandle is NULL!";
    } else {
        eventInstance->messageTrackingId = 5;

        MAP_HANDLE propMap = IHM(Properties)(eventInstance->messageHandle);
        std::stringstream propStream;
        propStream << "PropMsg_" << eventInstance->messageTrackingId;
        std::string propText = propStream.str();

        if (Map_AddOrUpdate(propMap, "PropName", propText.c_str()) != MAP_OK) {
            BOOST_LOG_TRIVIAL(error) << "Map_AddOrUpdate Failed!";
        }

        // Setting messages with the same UUID values just for example.
        IHM(SetMessageId)(eventInstance->messageHandle, "dec14a98-c5fc-430e-b4e3-33c1c434dcaf");
        IHM(SetCorrelationId)(eventInstance->messageHandle, "33c1c434dcaf-c5fc-430e-b4e3-dec14a98");
        IHM(SetContentTypeSystemProperty)(eventInstance->messageHandle, "application/json");
        IHM(SetContentEncodingSystemProperty)(eventInstance->messageHandle, "utf-8");

        this->addToEventInstanceMapping(eventInstance);
        if (IHC(SendEventAsync)(this->clientHandle, eventInstance->messageHandle, confirmationCallback,
                                eventInstance) != IOTHUB_CLIENT_OK) {
            BOOST_LOG_TRIVIAL(error) << "IoTHubClient_SendEventAsync..........FAILED!";
            this->addToNotConfirmedIntances(eventInstance);
        } else {
            BOOST_LOG_TRIVIAL(debug)
                << "IoTHubClient_SendEventAsync accepted data for transmission to IoT Hub. Message is: " << messageStr
                << ", tracking id is "
                << eventInstance->messageTrackingId << ".";
            this->removeFromEventInstanceMapping(eventInstance);
        }
    }
}