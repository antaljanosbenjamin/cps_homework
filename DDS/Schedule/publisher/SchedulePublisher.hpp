//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_SCHEDULEPUBLISHER_HPP
#define PROJECT_SCHEDULEPUBLISHER_HPP

#include "DDS/Schedule/common/Schedule.hpp"
#include "DDS/AbstractPublisher.hpp"

class SchedulePublisher : public AbstractPublisher<Schedule> {
public:
    SchedulePublisher();

    ~SchedulePublisher();

    void publish(bool scheduled, unsigned long until, unsigned long sentTS);
};


#endif //PROJECT_SCHEDULEPUBLISHER_HPP
