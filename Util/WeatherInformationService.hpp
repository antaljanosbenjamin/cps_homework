//
// Created by kovi on 12/7/17.
//

#ifndef PROJECT_WEATHERINFORMATIONSERVICE_HPP
#define PROJECT_WEATHERINFORMATIONSERVICE_HPP

#include <string>

#include <boost/date_time/posix_time/posix_time.hpp>

class WeatherInformationError : public std::runtime_error {
public:

    WeatherInformationError(const std::string &cause);

    virtual ~WeatherInformationError();
};

class WeatherInformationService {
private:

    std::string apiKey;

    static std::string baseUrl;

    static size_t WriteCallback(std::string *, char *ptr, size_t size, size_t nmemb);


public:
    struct WeatherInfo {
        int temperature;
        boost::posix_time::ptime temperatureTimestamp;
        int pollution;
        boost::posix_time::ptime pollutionTimestamp;

    };

    WeatherInformationService(const std::string &apiKey);

    WeatherInfo getWeatherInfo(float latitude, float longitude, size_t precision);

    std::string getWeatherInfoAsString(float latitude, float longitude, size_t precision);


};


#endif //PROJECT_WEATHERINFORMATIONSERVICE_HPP
