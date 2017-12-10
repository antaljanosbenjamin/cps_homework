//
// Created by kovi on 12/6/17.
//

#ifndef PROJECT_WEATHERPUBLISHER_HPP
#define PROJECT_WEATHERPUBLISHER_HPP

#ifndef __HELLO_PUBLISHER__
#define __HELLO_PUBLISHER__

#include <string>
#include <dds/dds.hpp>
#include "DDS/Weather/common/Weather.hpp"
#include "DDS/AbstractPublisher.hpp"

class WeatherPublisher : public AbstractPublisher<Weather> {
public:
    WeatherPublisher();

    ~WeatherPublisher();

    void publish(double temperature, unsigned long tempTimestamp, int32_t pollution, unsigned long pollTimestamp);
};

#endif

#endif //PROJECT_WEATHERPUBLISHER_HPP
