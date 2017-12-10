//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_SCONFIGPUBLISHER_HPP
#define PROJECT_SCONFIGPUBLISHER_HPP

#include "DDS/Config/common/Config.hpp"
#include "DDS/AbstractPublisher.hpp"

class ConfigPublisher : public AbstractPublisher<Config> {
public:
    ConfigPublisher();

    ~ConfigPublisher();

    void publish(double maxTemperature, unsigned long maxPollution, unsigned long minHumidity, unsigned long maxHumidity);
};


#endif //PROJECT_SCONFIGPUBLISHER_HPP
