//
// Created by kovi on 12/6/17.
//

#ifndef PROJECT_WEATHERSUBSCRIBER_HPP
#define PROJECT_WEATHERSUBSCRIBER_HPP

#include "DDS/AbstractSubscriber.hpp"
#include "DDS/Weather/common/Weather.hpp"

class WeatherSubscriber : public AbstractSubscriber<Weather> {
public:

    WeatherSubscriber();

    ~WeatherSubscriber() override;
};

#endif //PROJECT_WEATHERSUBSCRIBER_HPP
