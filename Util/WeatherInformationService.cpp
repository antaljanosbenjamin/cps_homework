//
// Created by kovi on 12/7/17.
//
#include <sstream>

#include <boost/date_time/posix_time/posix_time.hpp>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <rapidjson/document.h>

#include "WeatherInformationService.hpp"

using namespace boost::date_time;
using namespace boost::posix_time;

WeatherInformationError::WeatherInformationError(const std::string &cause) : std::runtime_error(cause) {}

WeatherInformationError::~WeatherInformationError() {}


std::string WeatherInformationService::baseUrl("http://api.airvisual.com/");

size_t WeatherInformationService::WriteCallback(std::string *result, char *rawResponse, size_t size, size_t nmemb) {
    result->append(rawResponse, size * nmemb);
    return size * nmemb;
}

WeatherInformationService::WeatherInformationService(const std::string &apiKey) :
        apiKey(apiKey) {}

WeatherInformationService::WeatherInfo
WeatherInformationService::getWeatherInfo(float latitude, float longitude, size_t precision) {

    std::string stringWeatherInfo = this->getWeatherInfoAsString(longitude, latitude, precision);

    rapidjson::Document document;
    if (document.Parse(stringWeatherInfo.c_str()).HasParseError()) {
        throw WeatherInformationError("Can't parse response!");
    }
    assert(document.IsObject());
    assert(document.HasMember("data"));
    assert(document["data"].IsObject());
    int temperature = document["data"]["current"]["weather"]["tp"].GetInt();
    std::string tempTs = document["data"]["current"]["weather"]["ts"].GetString();
    int pollution = document["data"]["current"]["pollution"]["aqius"].GetInt();
    std::string pollTs = document["data"]["current"]["pollution"]["ts"].GetString();

    parse_delimited_time<ptime>(pollTs.substr(0, pollTs.size() - 1), 'T');
    return WeatherInfo{temperature, parse_delimited_time<ptime>(tempTs.substr(0, tempTs.size() - 1), 'T'), pollution,
                       parse_delimited_time<ptime>(pollTs.substr(0, pollTs.size() - 1), 'T')};
}

std::string WeatherInformationService::getWeatherInfoAsString(float latitude, float longitude, size_t precision) {
    std::stringstream urlBuilder;
    urlBuilder << baseUrl << "v2/nearest_city?lat=" << std::setprecision(precision) << latitude << "&lon=" << longitude
               << "&key="
               << this->apiKey;

    std::string response;

    try {
        curlpp::Cleanup cleaner;
        curlpp::Easy request;

        using namespace std::placeholders;

        curlpp::options::WriteFunction *test = new curlpp::options::WriteFunction(
                std::bind(WriteCallback, &response, _1, _2, _3));
        request.setOpt(test);

        request.setOpt(new curlpp::options::Url(urlBuilder.str()));
        request.perform();

    }
    catch (curlpp::LogicError &e) {
        throw WeatherInformationError(e.what());
    }
    catch (curlpp::RuntimeError &e) {
        throw WeatherInformationError(e.what());
    }

    return response;
}