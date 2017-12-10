//
// Created by kovi on 12/6/17.
//

#include <thread>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/greg_year.hpp>

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
        HumidityEdge edge(weatherAPIKey, connectionString, "");
        edge.start();
        std::this_thread::sleep_for(15s);
        edge.stop();
        std::cout << "stopped!" << std::endl;
        edge.start();
        std::this_thread::sleep_for(15s);
        edge.stop();
        std::cout << "stopped!" << std::endl;

    } else if (argv[1][0] == 's') {
        WeatherSubscriber sub;
        sub.startReceiving();
        dds::domain::DomainParticipant::finalize_participant_factory();
    } else if (argv[1][0] == 'a') {
        std::function<void(const rapidjson::Document &)> consumer = [](const rapidjson::Document &) {
            std::cout << "I got it..." << std::endl;
        };
        IoTHubClient client(connectionString, consumer, false, 350);
        std::ifstream myfile;
        double value;
        auto timestamp = second_clock::local_time() - hours(200);
        myfile.open("/home/kovi/tmp/input.csv", std::ios::in);
        myfile >> value;
        client.sendMessage(getMessage(timestamp, value));
        std::this_thread::sleep_for(45s);
        while (myfile >> value) {
            timestamp += minutes(10);
            client.sendMessage(getMessage(timestamp, value));
            std::this_thread::sleep_for(10ms);
        }
        std::this_thread::sleep_for(100s);
    } else if (argv[1][0] == 'w') {
        WeatherInformationService service(weatherAPIKey);
        std::cout << service.getWeatherInfoAsString(47.4985f, 19.0527f, 4);
        std::cout << service.getWeatherInfo(47.4985f, 19.0527f, 4).pollutionTimestamp;
    }
}
