//
// Created by kovi on 12/10/17.
//

#include <iostream>
#include <string>
#include <dds/dds.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "ConfigPublisher.hpp"

using namespace dds::core;
using namespace dds::domain;
using namespace dds::topic;
using namespace dds::pub;

ConfigPublisher::ConfigPublisher() : AbstractPublisher(42, "config") {
}

void ConfigPublisher::publish(double maxTemperature, unsigned long maxPollution, unsigned long minHumidity, unsigned long maxHumidity) {

    // Create an instance
    Config instance;
    instance.maxTemperature() = maxTemperature;
    instance.maxPollution() = maxPollution;
    instance.minHumidity() = minHumidity;
    instance.maxHumidity() = maxHumidity;


    this->publishData(instance);

}

ConfigPublisher::~ConfigPublisher() {
}