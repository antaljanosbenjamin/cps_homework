//
// Created by kovi on 12/10/17.
//

#include "HumiditySubscriber.hpp"


HumiditySubscriber::HumiditySubscriber()
        : AbstractSubscriber(1, "DHT_Humidity", 1) {

}

HumiditySubscriber::~HumiditySubscriber() {
}