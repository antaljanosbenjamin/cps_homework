//
// Created by kovi on 12/6/17.
//

#ifndef PROJECT_WEATHERPUBLISHER_HPP
#define PROJECT_WEATHERPUBLISHER_HPP

#ifndef __HELLO_PUBLISHER__
#define __HELLO_PUBLISHER__

#include <string>
#include <dds/dds.hpp>
#include "Weather.hpp"

class WeatherPublisher {
public:
    WeatherPublisher(int domain_id, const std::string& topic_name);
    ~WeatherPublisher();

    void publish(int sample_count);

private:
    static const int MaxConsecutiveWriteErrors = 10;
    dds::domain::DomainParticipant participant;
    dds::topic::Topic<Weather> topic;
    dds::pub::DataWriter<Weather> writer;
};

#endif

#endif //PROJECT_WEATHERPUBLISHER_HPP
