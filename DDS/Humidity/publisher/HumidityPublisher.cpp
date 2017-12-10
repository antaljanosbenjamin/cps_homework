//
// Created by kovi on 12/10/17.
//

#include <iostream>
#include <string>
#include <dds/dds.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "HumidityPublisher.hpp"

using namespace dds::core;
using namespace dds::domain;
using namespace dds::topic;
using namespace dds::pub;

HumidityPublisher::
HumidityPublisher() :
        AbstractPublisher(1,"DHT_Humidity") {
}

void HumidityPublisher::publish(bool scheduled, unsigned long until, unsigned long sentTS) {

    // Create an instance
    UvegHaz instance;

    this->publishData(instance);

}

HumidityPublisher::~HumidityPublisher() {
}