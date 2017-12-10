//
// Created by kovi on 12/10/17.
//

#include "ScheduleSubscriber.hpp"


ScheduleSubscriber::ScheduleSubscriber()
        : AbstractSubscriber(42, "schedule_info", 1) {

}

void ScheduleSubscriber::receiveData(const Schedule &data) {

    std::cout << "Data received! The schedule is " << data.scheduled() << std::endl;

}

ScheduleSubscriber::~ScheduleSubscriber() {
}