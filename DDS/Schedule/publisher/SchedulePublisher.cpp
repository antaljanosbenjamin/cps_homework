//
// Created by kovi on 12/10/17.
//

#include <iostream>
#include <string>
#include <dds/dds.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "SchedulePublisher.hpp"

using namespace dds::core;
using namespace dds::domain;
using namespace dds::topic;
using namespace dds::pub;

SchedulePublisher::
SchedulePublisher() :
        AbstractPublisher(42,"schedule_info") {
}

void SchedulePublisher::publish(bool scheduled, unsigned long until, unsigned long sentTS) {

    // Create an instance
    Schedule instance;
    instance.scheduled() = scheduled;
    instance.until() = until;
    instance.sentTS() = sentTS;

    this->publishData(instance);

}

SchedulePublisher::~SchedulePublisher() {
}