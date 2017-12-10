//
// Created by kovi on 12/6/17.
//

#include <iostream>
#include <string>
#include <dds/dds.hpp>
#include "WeatherSubscriber.hpp"

using namespace dds::core;
using namespace dds::core::status;
using namespace dds::domain;
using namespace dds::topic;
using namespace dds::sub;

WeatherSubscriber::WeatherSubscriber()
        : AbstractSubscriber(42, "weather_info", 1){

}

WeatherSubscriber::~WeatherSubscriber() {
}
