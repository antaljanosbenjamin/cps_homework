//
// Created by kovi on 12/6/17.
//

/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*****************************************************************************/

#include <iostream>
#include <string>
#include <dds/dds.hpp>
#include "Weather/publisher/WeatherPublisher.hpp"

using namespace dds::core;
using namespace dds::domain;
using namespace dds::topic;
using namespace dds::pub;

WeatherPublisher::
WeatherPublisher(int domain_id, const std::string &topic_name) :
        participant(domain_id),
        topic(participant, topic_name),
        writer(Publisher(participant), topic) {
}

void WeatherPublisher::publish(int sample_count) {

    // Create an instance
    Weather instance;
    instance.temperature() = 3.4;
    instance.pollution() = 6;

    // Write samples from the instance
    std::cout << "Sending data..." << std::endl;
    int errorCount = 0;
    int success = 0;
    while (success < 10 && errorCount < MaxConsecutiveWriteErrors) {

        try {
            instance.pollution() = success;
            writer.write(instance);
            std::cout << "Success!" << std::endl;
            success++;
        } catch (const TimeoutError& error) {
            std::cout << error.what() << std::endl;
            errorCount++;
            if (errorCount == MaxConsecutiveWriteErrors) {
                std::cerr << "! Reached maximum number of failure, "
                          << "stopping writer..." << std::endl;
                break;
            }
        }
        rti::util::sleep(Duration::from_millisecs(1000));
    }

    writer.wait_for_acknowledgments(Duration::from_secs(10));

}

WeatherPublisher::~WeatherPublisher() {
}
