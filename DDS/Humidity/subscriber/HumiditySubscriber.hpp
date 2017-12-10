//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_HUMIDITYSUBSCRIBER_HPP
#define PROJECT_HUMIDITYSUBSCRIBER_HPP

#include "DDS/AbstractSubscriber.hpp"
#include "DDS/Humidity/common/UvegHaz.hpp"

class HumiditySubscriber  : public AbstractSubscriber<UvegHaz> {
public:

    HumiditySubscriber();

    ~HumiditySubscriber() override;
};


#endif //PROJECT_HUMIDITYSUBSCRIBER_HPP
