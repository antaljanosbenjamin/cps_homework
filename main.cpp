//
// Created by kovi on 12/6/17.
//

#include <thread>

#include <boost/date_time/posix_time/posix_time.hpp>

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <fstream>
#include <Devices/HumidityEdge.hpp>

#include "DDS/Weather/publisher/WeatherPublisher.hpp"
#include "DDS/Weather/subscriber/WeatherSubscriber.hpp"
#include "AzureWrapper/IoTHubClient.hpp"
#include "Util/WeatherInformationService.hpp"

using namespace rapidjson;
using namespace boost::posix_time;
using namespace std::chrono_literals;

std::string connectionString(
        "hehe");

std::string weatherAPIKey("hihi");

Document getMessage(boost::posix_time::ptime time, double humidityValue) {

    std::string timestamp = to_iso_extended_string(time);

    Document message;
    message.SetObject();
    auto &allocator = message.GetAllocator();
    message.AddMember("deviceId", Value("myFirstDevice", allocator), allocator);
    message.AddMember("humidityValue", Value(humidityValue), allocator);
    message.AddMember("led", Value(humidityValue > 77 ? 1 : 0), allocator);
    message.AddMember("timestamp", Value(timestamp.c_str(), allocator), allocator);

    return message;
}

int main(int argc, const char **argv) {

    if (argc < 2) {
        return -1;
    }

    if (argv[1][0] == 'e') {
        HumidityEdge edge(argv[2], argv[3], argv[4]);
        edge.start();
        // dds::domain::DomainParticipant::finalize_participant_factory();
        while(true){
            std::string input;
            std::cin >> input;
            if (input == "stop"){
                edge.stop();
            } else if (input == "start"){
                edge.start();
            } else if (input == "quit"){
                edge.stop();
                return 0;
            }
        }
    } else if (argv[1][0] == 'c') {
        WeatherSubscriber sub;
        //sub.startReceiving();
    } else if (argv[1][0] == 'h') {

    }
}
