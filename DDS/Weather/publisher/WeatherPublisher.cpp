//
// Created by kovi on 12/6/17.
//

#include <iostream>
#include <string>
#include <dds/dds.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "WeatherPublisher.hpp"

using namespace dds::core;
using namespace dds::domain;
using namespace dds::topic;
using namespace dds::pub;

WeatherPublisher::
WeatherPublisher() :
        AbstractPublisher(42,"weather_info") {
}

void WeatherPublisher::publish(double temperature, unsigned long tempTimestamp, int32_t pollution,
                               unsigned long pollTimestamp) {

    // Create an instance
    Weather instance;
    instance.temperature() = temperature;
    instance.tempTS() = tempTimestamp;
    instance.pollution() = pollution;
    instance.pollTS() = pollTimestamp;

    this->publishData(instance);

}

WeatherPublisher::~WeatherPublisher() {
}
