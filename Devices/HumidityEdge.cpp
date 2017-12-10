//
// Created by kovi on 12/10/17.
//

#include <chrono>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <fstream>

#include "Util/DateHelper.hpp"
#include "HumidityEdge.hpp"

using namespace rapidjson;
using namespace std::chrono_literals;
using namespace boost::posix_time;

HumidityEdge::HumidityEdge(const std::string &weatherApiKey, const std::string &azureConnectionString,
                           const std::string &scheduleFileName) :
        weatherApiKey(weatherApiKey),
        azureConnectionString(azureConnectionString),
        scheduleFileName(scheduleFileName),
        weatherService(new WeatherInformationService(weatherApiKey)),
        weatherPublisher(new WeatherPublisher()),
        schedulePublisher(new SchedulePublisher()),
        configPublisher(new ConfigPublisher()),
        decisionSubscriber(new DecisionSubscriber()),
        iotClient(new IoTHubClient(azureConnectionString,
                                   [&](const Document &message) { this->receiveMessageFromCloud(message); })),
        isRunning(false) {

}

Document HumidityEdge::getJSON(const WeatherInformationService::WeatherInfo &weatherInfo) {

    std::string tempTS = to_iso_extended_string(weatherInfo.temperatureTimestamp);
    std::string pollTS = to_iso_extended_string(weatherInfo.pollutionTimestamp);
    std::string messageTS = to_iso_extended_string(second_clock::local_time());

    Document message;
    message.SetObject();
    auto &allocator = message.GetAllocator();
    message.AddMember("temperature", Value(weatherInfo.temperature), allocator);
    message.AddMember("temperatureTimestamp", Value(tempTS.c_str(), allocator), allocator);
    message.AddMember("pollution", Value(weatherInfo.pollution), allocator);
    message.AddMember("pollutionTimestamp", Value(pollTS.c_str(), allocator), allocator);

    message.AddMember("messageTimestamp", Value(messageTS.c_str(), allocator), allocator);
    message.AddMember("type", Value("weather_from_edge", allocator), allocator);

    return message;
}

void HumidityEdge::readSchedule() {
    std::ifstream scheduleFile;
    scheduleFile.open(this->scheduleFileName, std::ios::in);
    std::string startTS;
    std::string stopTS;
    while (scheduleFile) {
        std::getline(scheduleFile, startTS, ',');
        std::getline(scheduleFile, stopTS, ',');
        ptime startTimestamp = from_iso_string(startTS);
        ptime stopTimestamp = from_iso_string(stopTS);
        schedule.emplace(startTimestamp, stopTimestamp);
    }

}

void HumidityEdge::receiveMessageFromCloud(const rapidjson::Document &message) {

    double maxTemperature = message["maximumTemperature"].GetDouble();
    unsigned long maxPollution = message["maximumPollution"].GetUint64();
    unsigned long minHumidity = message["minimumHumidity"].GetUint64();
    unsigned long maxHumidity = message["maximumHumidity"].GetUint64();
    this->configPublisher->publish(maxTemperature, maxPollution, minHumidity, maxHumidity);
}

void HumidityEdge::start() {

    if (this->workerThread.joinable()) {
        return;
    }

    this->iotClient->start();
    isRunning.store(true);

    this->readSchedule();

    this->workerThread = std::thread([this]() {
        while (this->isRunning.load()) {

            try {

                WeatherInformationService::WeatherInfo weatherInfo = this->weatherService->getWeatherInfo(47.4985f,
                                                                                                          19.0527f, 4);
                this->weatherPublisher->publish(weatherInfo.temperature,
                                                DateHelper::toUnixTimestamp(weatherInfo.temperatureTimestamp),
                                                weatherInfo.pollution,
                                                DateHelper::toUnixTimestamp(weatherInfo.pollutionTimestamp));

                this->iotClient->sendMessage(this->getJSON(weatherInfo));

            } catch (WeatherInformationError wis) {
                BOOST_LOG_TRIVIAL(error) << wis.what();
            }

            ptime now = second_clock::local_time();
            while (this->schedule.size() != 0 && this->schedule.begin()->second < now) {
                this->schedule.erase(this->schedule.begin());
            }

            if (this->schedule.size() != 0) {
                auto nextSchedule = this->schedule.begin();
                if (nextSchedule->first < now) {
                    this->schedulePublisher->publish(true, DateHelper::toUnixTimestamp(nextSchedule->second),
                                                     DateHelper::toUnixTimestamp(now));
                } else {
                    this->schedulePublisher->publish(false, DateHelper::toUnixTimestamp(nextSchedule->first),
                                                     DateHelper::toUnixTimestamp(now));
                }
            }

            std::this_thread::sleep_for(3s);
        }
    });


}


void HumidityEdge::archiveDecisionData(const DecisionInfo &data) {
    Document lastWeatherJSON;
    const Weather& lastWeather = data.lastWeather();
    lastWeatherJSON.SetObject();



    // TODO
    /*Document messateToCloud;
    messateToCloud.SetObject();
    auto &allocator = messateToCloud.GetAllocator();
    messateToCloud.AddMember("temperature", Value(weatherInfo.temperature), allocator);
    messateToCloud.AddMember("temperatureTimestamp", Value(tempTS.c_str(), allocator), allocator);
    messateToCloud.AddMember("pollution", Value(weatherInfo.pollution), allocator);
    messateToCloud.AddMember("pollutionTimestamp", Value(pollTS.c_str(), allocator), allocator);

    messateToCloud.AddMember("messageTimestamp", Value(messageTS.c_str(), allocator), allocator);
    messateToCloud.AddMember("type", Value("weather_from_edge", allocator), allocator);*/
}

void HumidityEdge::stop() {
    this->isRunning.store(false);
    if (this->workerThread.joinable()) {
        this->workerThread.join();
    }
    this->iotClient->stop();
    this->decisionSubscriber->stopReceiving();

}

HumidityEdge::~HumidityEdge() {}