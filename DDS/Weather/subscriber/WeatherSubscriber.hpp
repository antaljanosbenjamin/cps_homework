//
// Created by kovi on 12/6/17.
//

#ifndef PROJECT_WEATHERSUBSCRIBER_HPP
#define PROJECT_WEATHERSUBSCRIBER_HPP

#include <string>
#include <dds/dds.hpp>
#include <atomic>

#include "DDS/Weather/common/Weather.hpp"

class WeatherSubscriber : public dds::sub::NoOpDataReaderListener<Weather> {
public:

    WeatherSubscriber(int domain_id, const std::string &topic_name, int pollSeconds);

    ~WeatherSubscriber();

    void on_data_available(dds::sub::DataReader<Weather> &reader) override;

    void startReceiving();

    void stopReceiving();

private:
    dds::domain::DomainParticipant participant;
    dds::topic::Topic<Weather> topic;
    dds::sub::DataReader<Weather> reader;

    std::atomic<int> pollSeconds;
};

#endif //PROJECT_WEATHERSUBSCRIBER_HPP
