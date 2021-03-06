//
// Created by kovi on 12/10/17.
//

#include <chrono>

#include "HumidityController.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <Util/DateHelper.hpp>

using namespace boost::posix_time;
using namespace std::chrono_literals;

std::chrono::seconds HumidityController::stopTime = 5s;

HumidityController::HumidityController() :
        weatherSubscriber(new WeatherSubscriber()),
        scheduleSubscriber(new ScheduleSubscriber()),
        configSubscriber(new ConfigSubscriber()),
        humiditySubscriber(new HumiditySubscriber()),
        decisionPublisher(new DecisionPublisher()),
        isRunning(false),
        workerThread(),
        lastWeather(nullptr),
        lastSchedule(nullptr),
        actualConfig(new Config(35, 25u, 45u, 55u)),
        lastHumidity(nullptr),
        lastDecision(),
        lastDecisionTS(second_clock::local_time()),
        mutex() {

}

HumidityController::~HumidityController() {
    stop();
}

void HumidityController::start() {
    std::lock_guard<std::mutex> globalLock(this->mutex);
    this->isRunning.store(true);
    using namespace std::placeholders;
    weatherSubscriber->startReceiving(std::bind(&HumidityController::receiveWeather, this, _1));
    scheduleSubscriber->startReceiving(std::bind(&HumidityController::receiveSchedule, this, _1));
    configSubscriber->startReceiving(std::bind(&HumidityController::receiveConfig, this, _1));
    humiditySubscriber->startReceiving(std::bind(&HumidityController::receiveHumidity, this, _1));

    this->workerThread = std::thread([this]() {

        long loopsToWorkToCast = 5min / stopTime;
        size_t loopsToWork = 0;

        if (loopsToWorkToCast > std::numeric_limits<size_t>::max()) {
            loopsToWork = std::numeric_limits<size_t>::max();
        } else if (loopsToWorkToCast > 0) {
            loopsToWork = (size_t) loopsToWorkToCast;
        }
        size_t counter = loopsToWork;
        while (this->isRunning.load()) {
            if (counter == loopsToWork) {
                counter = 0;
                this->makeDecision();
            }
            counter++;
            std::this_thread::sleep_for(stopTime);
        }
    });
}

void HumidityController::stop() {
    std::lock_guard<std::mutex> globalLock(this->mutex);
    this->isRunning.store(false);
    if (this->workerThread.joinable()) {
        this->workerThread.join();
    }
    weatherSubscriber->stopReceiving();
    scheduleSubscriber->stopReceiving();
    configSubscriber->stopReceiving();
    humiditySubscriber->stopReceiving();

}

bool HumidityController::isAllDataAvailable() {
    if (lastWeather == nullptr || lastSchedule == nullptr || actualConfig == nullptr || lastHumidity == nullptr) {
        return false;
    }

    std::string ts;
    ptime now = second_clock::local_time();
    ptime lastTempTS = DateHelper::toPTime(lastWeather->tempTS());
    ts = to_iso_extended_string(lastTempTS);
    ptime lastPollTS = DateHelper::toPTime(lastWeather->pollTS());
    ts = to_iso_extended_string(lastPollTS);
    // it should newer, but the airvisual weather api provides new data only once an hour
    if (now - lastTempTS > minutes(1500) || now - lastPollTS > minutes(1500)) {
        return false;
    }

    ptime lastScheduleUntil = DateHelper::toPTime(lastSchedule->until());
    if (lastScheduleUntil > now) {
        // just log it
    }

    ptime lastHumdidityTS = DateHelper::toPTime(lastHumidity->TimeStamp());
    if (now - lastHumdidityTS > minutes(30)) {
        return false;
    }

    return true;
}

void HumidityController::receiveWeather(const Weather &weather) {
    {
        std::lock_guard<std::mutex> globalLock(this->mutex);
        BOOST_LOG_TRIVIAL(debug) << "Weather received!";
        if (!this->lastWeather) {
            this->lastWeather.reset(new Weather(weather));
        } else {
            *this->lastWeather = weather;
        }
    }
    makeDecision();
}

void HumidityController::receiveConfig(const Config &config) {
    {
        std::lock_guard<std::mutex> globalLock(this->mutex);
        BOOST_LOG_TRIVIAL(debug) << "Config received!";
        if (config.minHumidity() >= config.maxHumidity()) {
            BOOST_LOG_TRIVIAL(debug) << "Minimum humidity must be lesser than maximum humdity!";
            return;
        }
        if (!this->actualConfig) {
            this->actualConfig.reset(new Config(config));
        } else {
            *this->actualConfig = config;
        }
    }
    makeDecision();
}

void HumidityController::receiveSchedule(const Schedule &schedule) {
    {
        std::lock_guard<std::mutex> globalLock(this->mutex);
        BOOST_LOG_TRIVIAL(debug) << "Schedule received!";
        if (!this->lastSchedule) {
            this->lastSchedule.reset(new Schedule(schedule));
        } else {
            *this->lastSchedule = schedule;
        }
    }
    makeDecision();
}

void HumidityController::receiveHumidity(const UvegHaz &humidity) {
    {
        std::lock_guard<std::mutex> globalLock(this->mutex);
        BOOST_LOG_TRIVIAL(debug) << "UvegHaz received!";
        if (!this->lastHumidity) {
            this->lastHumidity.reset(new UvegHaz(humidity));
        } else {
            *this->lastHumidity = humidity;
        }
    }
    makeDecision();
}

void HumidityController::makeDecision() {
    std::lock_guard<std::mutex> globalLock(this->mutex);

    this->lastDecisionTS = second_clock::local_time();

    if (!isAllDataAvailable()) {
        DecisionInfo data;
        data.decision() = Decision::CLOSE;
        data.decisionTS() = DateHelper::toUnixTimestamp(this->lastDecisionTS);
        decisionPublisher->publishData(data);
        this->lastDecision = Decision::CLOSE;
        return;
    }

    uint32_t maxHum = this->actualConfig->maxHumidity();
    uint32_t minHum = this->actualConfig->minHumidity();
    if (!this->lastSchedule->scheduled()) {
        maxHum = maxHum * 100 / 90;
    }

    BOOST_LOG_TRIVIAL(debug) << "Making real decision...";
    if (this->lastWeather->temperature() > this->actualConfig->maxTemperature() &&
        this->lastWeather->pollution() > this->actualConfig->maxPollution()) {
        this->lastDecision = Decision::CLOSE;
    } else if (this->lastDecision == Decision::CLOSE && this->lastHumidity->Value() >= maxHum) {
        this->lastDecision = Decision::OPEN;
    } else if (this->lastDecision == Decision::OPEN && this->lastHumidity->Value() <= minHum) {
        this->lastDecision = Decision::CLOSE;
    }

    DecisionInfo data;
    data.lastHumidity() = *this->lastHumidity;
    data.lastWeather() = *this->lastWeather;
    data.lastSchedule() = *this->lastSchedule;
    data.config() = *this->actualConfig;
    data.decision() = this->lastDecision;
    data.decisionTS() = DateHelper::toUnixTimestamp(this->lastDecisionTS);
    std::this_thread::sleep_for(1.1s);
    this->decisionPublisher->publishData(data);
}