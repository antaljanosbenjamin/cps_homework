//
// Created by kovi on 12/6/17.
//

#include <thread>

#include <boost/date_time/posix_time/posix_time.hpp>

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>

#include "Weather/publisher/WeatherPublisher.hpp"
#include "Weather/subscriber/WeatherSubscriber.hpp"
#include "AzureWrapper/IoTHubClient.hpp"

using namespace rapidjson;
using namespace boost::posix_time;
using namespace std::chrono_literals;

std::string connectionString("Copy here the connection string from Azure");

Document getMessage() {

    double avgWindSpeed = 60.0;
    std::string timestamp = to_iso_extended_string(second_clock::local_time());

    Document message;
    message.SetObject();
    auto &allocator = message.GetAllocator();
    message.AddMember("deviceId", Value("myFirstDevice", allocator), allocator);
    message.AddMember("windSpeed", Value(avgWindSpeed + (rand() % 15 + 2)), allocator);
    message.AddMember("timestamp", Value(timestamp.c_str(), allocator), allocator);

    return message;
}

int main(int argc, const char **argv) {

    if (argc < 2) {
        return -1;
    }

    if (argv[1][0] == 'p') {
        WeatherPublisher pub(0, "weather");
        pub.publish(50);
        dds::domain::DomainParticipant::finalize_participant_factory();
    } else if (argv[1][0] == 's') {
        WeatherSubscriber sub(0, "weather");
        sub.startReceiving();
        dds::domain::DomainParticipant::finalize_participant_factory();
    } else if (argv[1][0] == 'a') {
        std::function<void(const rapidjson::Document&)> consumer = [](const rapidjson::Document&){
            std::cout << "I got it..." << std::endl;
        };
        IoTHubClient client (connectionString, consumer, true, 350);
        std::this_thread::sleep_for(30s);
        client.sendMessage(getMessage());
    }
}
