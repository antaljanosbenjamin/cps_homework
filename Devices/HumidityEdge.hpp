//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_HUMIDITYEDGE_HPP
#define PROJECT_HUMIDITYEDGE_HPP

#include <string>
#include <memory>

#include <rapidjson/document.h>

#include "Util/WeatherInformationService.hpp"
#include "DDS/Weather/publisher/WeatherPublisher.hpp"
#include "DDS/Schedule/publisher/SchedulePublisher.hpp"
#include "AzureWrapper/IoTHubClient.hpp"

class HumidityEdge {
private:
    std::string weatherApiKey;
    std::string azureConnectionString;
    std::string scheduleFileName;

    std::unique_ptr<WeatherInformationService> weatherService;
    std::unique_ptr<WeatherPublisher> weatherPublisher;
    std::unique_ptr<SchedulePublisher> schedulePublisher;
    std::unique_ptr<IoTHubClient> iotClient;
    std::atomic<bool> isRunning;
    std::thread workerThread;
    std::set<std::pair<boost::posix_time::ptime,boost::posix_time::ptime>> schedule;


    void receiveMessageFromCloud(const rapidjson::Document & message );

    rapidjson::Document getJSON(const WeatherInformationService::WeatherInfo &weatherInfo);

    void readSchedule();
public:
    HumidityEdge(const std::string &weatherApiKey, const std::string &azureConnectionString,
                 const std::string &scheduleFileName);

    void start();

    void stop();

    ~HumidityEdge();

};


#endif //PROJECT_HUMIDITYEDGE_HPP
