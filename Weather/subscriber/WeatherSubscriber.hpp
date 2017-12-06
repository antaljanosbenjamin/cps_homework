//
// Created by kovi on 12/6/17.
//

#ifndef PROJECT_WEATHERSUBSCRIBER_HPP
#define PROJECT_WEATHERSUBSCRIBER_HPP

#include <string>
#include <dds/dds.hpp>
#include "Weather.hpp"

class WeatherSubscriber : public dds::sub::DataReaderListener<Weather> {
public:

    WeatherSubscriber(
            int domain_id,
            const std::string &topic_name);

    ~WeatherSubscriber();

    void on_requested_deadline_missed(dds::sub::DataReader<Weather> &,
                                      const dds::core::status::RequestedDeadlineMissedStatus &) override;

    void on_requested_incompatible_qos(dds::sub::DataReader<Weather> &,
                                       const dds::core::status::RequestedIncompatibleQosStatus &) override;

    void on_sample_rejected(dds::sub::DataReader<Weather> &, const dds::core::status::SampleRejectedStatus &) override;

    void
    on_liveliness_changed(dds::sub::DataReader<Weather> &, const dds::core::status::LivelinessChangedStatus &) override;

    void
    on_sample_lost(dds::sub::DataReader<Weather> &, const dds::core::status::SampleLostStatus &) override;

    void on_subscription_matched(dds::sub::DataReader<Weather> &,
                                 const dds::core::status::SubscriptionMatchedStatus &) override;

    void on_data_available(dds::sub::DataReader<Weather> &reader) override;

    void startReceiving();

    void stopReceiving();

private:
    static const int PollSeconds = 1;

    dds::domain::DomainParticipant participant;
    dds::topic::Topic<Weather> topic;
    dds::sub::DataReader<Weather> reader;

    int max_samples;
    int payload_size;
    int first_sample_id;
    int last_sample_id;
    int received_samples;
    int lost_samples;
};

#endif //PROJECT_WEATHERSUBSCRIBER_HPP
