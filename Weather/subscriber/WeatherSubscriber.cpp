//
// Created by kovi on 12/6/17.
//

/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

#include <iostream>
#include <string>
#include <dds/dds.hpp>
#include "WeatherSubscriber.hpp"

using namespace dds::core;
using namespace dds::core::status;
using namespace dds::domain;
using namespace dds::topic;
using namespace dds::sub;

WeatherSubscriber::WeatherSubscriber(int domain_id, const std::string &topic_name)
        : participant(domain_id), topic(participant, topic_name),
          reader(Subscriber(participant), topic), max_samples(0), payload_size(0), first_sample_id(-1),
          last_sample_id(0), received_samples(0), lost_samples(0) {
    reader.listener(this, StatusMask::all());
}


void WeatherSubscriber::on_requested_deadline_missed(
        DataReader<Weather> &,
        const RequestedDeadlineMissedStatus &) {
    std::cout << "->Callback: requested deadline missed." << std::endl;
}

void WeatherSubscriber::on_requested_incompatible_qos(
        DataReader<Weather> &,
        const RequestedIncompatibleQosStatus &) {
    std::cout << "->Callback: requested incompatible QoS." << std::endl;
}

void WeatherSubscriber::on_sample_rejected(
        DataReader<Weather> &,
        const SampleRejectedStatus &) {
    std::cout << "->Callback: sample rejected." << std::endl;
}

void WeatherSubscriber::on_liveliness_changed(
        DataReader<Weather> & reader,
        const LivelinessChangedStatus &) {
    std::cout << "->Callback: liveliness changed." << std::endl;
    on_data_available(reader);
}

void WeatherSubscriber::on_sample_lost(
        DataReader<Weather> &,
        const SampleLostStatus &) {
    lost_samples++;
    std::cout << "->Callback: sample lost." << std::endl;
}

void WeatherSubscriber::on_subscription_matched(
        DataReader<Weather> &,
        const SubscriptionMatchedStatus &) {
    std::cout << "->Callback: subscription matched" << std::endl;
}

void WeatherSubscriber::on_data_available(DataReader<Weather> &reader) {
    LoanedSamples<Weather> samples = reader.take();
    for (LoanedSamples<Weather>::iterator it = samples.begin(); it != samples.end(); it++) {
        std::cout << "Data received!" << std::endl;
        if (it->info().valid()) {
            received_samples++;
            std::cout << "Data received! The temperature is " << it->data().temperature() << " and the pollution is "
                      << it->data().pollution() << std::endl;
        }
    }
}

void WeatherSubscriber::startReceiving() {
    while (true) {
        rti::util::sleep(Duration::from_secs(PollSeconds));
    }
}

void WeatherSubscriber::stopReceiving() {
    reader.listener(NULL, StatusMask::none());
}


WeatherSubscriber::~WeatherSubscriber() {
    reader.listener(NULL, StatusMask::none());
}
