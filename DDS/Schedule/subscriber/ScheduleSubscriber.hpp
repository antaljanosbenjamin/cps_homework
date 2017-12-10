//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_SCHEDULESUBSCRIBER_HPP
#define PROJECT_SCHEDULESUBSCRIBER_HPP




#include "DDS/AbstractSubscriber.hpp"
#include "DDS/Schedule/common/Schedule.hpp"

class ScheduleSubscriber  : public AbstractSubscriber<Schedule> {
public:

    ScheduleSubscriber();

    ~ScheduleSubscriber() override;

    void receiveData( const Schedule & data);
};


#endif //PROJECT_SCHEDULESUBSCRIBER_HPP
