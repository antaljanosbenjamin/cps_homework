//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_HUMIDITYCONTROLLER_HPP
#define PROJECT_HUMIDITYCONTROLLER_HPP

#include <memory>
#include <thread>
#include <mutex>

#include <boost/date_time/posix_time/posix_time.hpp>

#include "DDS/Weather/subscriber/WeatherSubscriber.hpp"
#include "DDS/Config/subscriber/ConfigSubscriber.hpp"
#include "DDS/Schedule/subscriber/ScheduleSubscriber.hpp"
#include "DDS/Humidity/subscriber/HumiditySubscriber.hpp"
#include "DDS/Decision/publisher/DecisionPublisher.hpp"

class HumidityController {
public:
    HumidityController();
    ~HumidityController();

    void start();
    void stop();

private:
    std::unique_ptr<WeatherSubscriber> weatherSubscriber;
    std::unique_ptr<ScheduleSubscriber> scheduleSubscriber;
    std::unique_ptr<ConfigSubscriber> configSubscriber;
    std::unique_ptr<HumiditySubscriber> humiditySubscriber;
    std::unique_ptr<DecisionPublisher> decisionPublisher;

    std::atomic<bool> isRunning;
    std::thread workerThread;
    std::unique_ptr<Weather> lastWeather;
    std::unique_ptr<Schedule> lastSchedule;
    std::unique_ptr<Config> actualConfig;
    std::unique_ptr<UvegHaz> lastHumidity;
    Decision lastDecision;
    boost::posix_time::ptime lastDecisionTS;

    std::mutex mutex;

    bool isAllDataAvailable();
    void receiveWeather(const Weather& weather);
    void receiveConfig(const Config& config);
    void receiveSchedule(const Schedule& schedule);
    void receiveHumidity(const UvegHaz& humidity);

    void makeDecision();
};


#endif //PROJECT_HUMIDITYCONTROLLER_HPP
