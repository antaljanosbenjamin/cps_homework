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

Document HumidityEdge::getWeatherInfoJSON(const WeatherInformationService::WeatherInfo &weatherInfo) {

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
        std::getline(scheduleFile, stopTS);
        if (startTS.length() > 0 && stopTS.length() > 0) {
            startTS.append(":00.000");
            stopTS.append(":00.000");
            ptime startTimestamp = time_from_string(startTS);
            ptime stopTimestamp = time_from_string(stopTS);
            schedule.emplace(startTimestamp, stopTimestamp);
        }
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
        size_t counter = 0;
        while (this->isRunning.load()) {
            counter++;
            std::this_thread::sleep_for(3s);
            if (counter < 10){
                continue;
            }
            counter = 0;
            try {

                WeatherInformationService::WeatherInfo weatherInfo = this->weatherService->getWeatherInfo(47.4985f,
                                                                                                          19.0527f, 4);
                this->weatherPublisher->publish(weatherInfo.temperature,
                                                DateHelper::toUnixTimestamp(weatherInfo.temperatureTimestamp),
                                                weatherInfo.pollution,
                                                DateHelper::toUnixTimestamp(weatherInfo.pollutionTimestamp));

                this->iotClient->sendMessage(this->getWeatherInfoJSON(weatherInfo));

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
        }
    });
}


void HumidityEdge::archiveDecisionData(const DecisionInfo &data) {
    Document messageToCloud;
    messageToCloud.SetObject();
    auto &allocator = messageToCloud.GetAllocator();

    /// Weather
    Document lastWeatherJSON;
    const Weather &lastWeather = data.lastWeather();
    lastWeatherJSON.SetObject();
    auto &weatherAlloc = lastWeatherJSON.GetAllocator();
    std::string tempTS = to_iso_extended_string(DateHelper::toPTime(lastWeather.tempTS()));
    std::string pollTS = to_iso_extended_string(DateHelper::toPTime(lastWeather.pollTS()));
    lastWeatherJSON.AddMember("temperature", Value(lastWeather.temperature()), weatherAlloc);
    lastWeatherJSON.AddMember("temperatureTimestamp", Value(tempTS.c_str(), weatherAlloc), weatherAlloc);
    lastWeatherJSON.AddMember("pollution", Value(lastWeather.pollution()), weatherAlloc);
    lastWeatherJSON.AddMember("pollutionTimestamp", Value(pollTS.c_str(), weatherAlloc), weatherAlloc);
    messageToCloud.AddMember("lastWeather", lastWeatherJSON, allocator);

    /// Config
    Document configJSON;
    const Config &config = data.config();
    configJSON.SetObject();
    auto &configAlloc = configJSON.GetAllocator();
    configJSON.AddMember("maxTemperature", Value(config.maxTemperature()), configAlloc);
    configJSON.AddMember("maxPollution", Value(config.maxPollution()), configAlloc);
    configJSON.AddMember("minHumidity", Value(config.minHumidity()), configAlloc);
    configJSON.AddMember("maxHumidity", Value(config.maxHumidity()), configAlloc);
    messageToCloud.AddMember("config", configJSON, allocator);

    /// Schedule
    Document lastScheduleJSON;
    const Schedule &lastSchedule = data.lastSchedule();
    lastScheduleJSON.SetObject();
    auto &scheduleAlloc = lastScheduleJSON.GetAllocator();
    std::string untilTS = to_iso_extended_string(DateHelper::toPTime(lastSchedule.until()));
    std::string sentTS = to_iso_extended_string(DateHelper::toPTime(lastSchedule.sentTS()));
    lastScheduleJSON.AddMember("scheduled", Value(lastSchedule.scheduled()), configAlloc);
    lastScheduleJSON.AddMember("until", Value(untilTS.c_str(), scheduleAlloc), scheduleAlloc);
    lastScheduleJSON.AddMember("sentTimestamp", Value(sentTS.c_str(), scheduleAlloc), scheduleAlloc);
    messageToCloud.AddMember("lastSchedule", lastScheduleJSON, allocator);

    /// Humidity
    Document lastHumidityJSON;
    const UvegHaz& lastHumidity = data.lastHumidity();
    lastHumidityJSON.SetObject();
    std::string lastHumidityTimestamp = to_iso_extended_string(DateHelper::toPTime(lastHumidity.TimeStamp()));
    auto & humidityAlloc = lastHumidityJSON.GetAllocator();
    lastHumidityJSON.AddMember("humidity", Value(lastHumidity.Value()), humidityAlloc);
    lastHumidityJSON.AddMember("humidityTimestamp", Value(lastHumidityTimestamp.c_str(), humidityAlloc), humidityAlloc);
    messageToCloud.AddMember("lastHumidity", lastHumidityJSON, allocator);

    /// Global
    std::string decisionTimestamp = to_iso_extended_string(DateHelper::toPTime(data.decisionTS()));
    std::string decision = data.decision() == Decision::OPEN ? "OPEN" : "CLOSED";
    messageToCloud.AddMember("decisionTimestamp", Value(sentTS.c_str(), allocator), allocator);
    messageToCloud.AddMember("decision", Value(decision.c_str(), allocator), allocator);

    this->iotClient->sendMessage(messageToCloud);
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