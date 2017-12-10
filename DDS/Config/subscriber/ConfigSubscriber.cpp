//
// Created by kovi on 12/10/17.
//

#include "ConfigSubscriber.hpp"


ConfigSubscriber::ConfigSubscriber()
        : AbstractSubscriber(42, "schedule_info", 1) {

}

void ConfigSubscriber::receiveData(const Config &data) {

    std::cout << "Data received! The maxtemp is " << data.maxTemperature() << std::endl;

}

ConfigSubscriber::~ConfigSubscriber() {
}