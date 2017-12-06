//
// Created by kovi on 12/6/17.
//

#ifndef PROJECT_IOTHUBCLIENT_HPP
#define PROJECT_IOTHUBCLIENT_HPP

#include <memory>
#include <map>
#include <mutex>
#include <atomic>
#include <set>
#include <thread>
#include <condition_variable>

#include "iothub_client.h"

#include <rapidjson/document.h>

typedef struct EventInstance {
    IOTHUB_MESSAGE_HANDLE messageHandle;
    size_t messageTrackingId;  // For tracking the messages within the user callback.
} EventInstance;

class IoTHubClient {
private:

    static std::mutex globalMutex;
    static std::map<EventInstance *, IoTHubClient *> eventInstanceMapping;
    static std::set<IoTHubClient *> livingClients;

    static IOTHUBMESSAGE_DISPOSITION_RESULT
    receiveMessage(IOTHUB_MESSAGE_HANDLE message, void *userContextCallback);

    static void confirmationCallback(IOTHUB_CLIENT_CONFIRMATION_RESULT result, void *userContextCallback);

    void doWork();

    void addToEventInstanceMapping(EventInstance *eventInstance);

    void removeFromEventInstanceMapping(EventInstance *eventInstance);

    void addToNotConfirmedIntances(EventInstance *eventInstance);

    void removeFromNotConfirmedIntances(EventInstance *eventInstance);

protected:

    const std::string connectionString;
    bool trace;
    uint32_t keepAlive;


    IOTHUB_CLIENT_LL_HANDLE clientHandle;
    bool initialized;

    std::mutex ownMutex;
    std::atomic_bool canRun;
    std::condition_variable conditionVariable;
    std::thread workerThread;
    std::set<EventInstance *> notConfirmedIntances;

public:
    static void init();

    static void finalize();

    IoTHubClient(const std::string &connectionString, bool trace, uint32_t keepAlive);

    virtual ~IoTHubClient();

    virtual void sendMessage(const rapidjson::Document &message);

};

#endif //PROJECT_IOTHUBCLIENT_HPP
