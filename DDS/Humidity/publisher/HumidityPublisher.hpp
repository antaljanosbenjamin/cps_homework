//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_HUMIDITYPUBLISHER_HPP
#define PROJECT_HUMIDITYPUBLISHER_HPP

#include "DDS/Humidity/common/UvegHaz.hpp"
#include "DDS/AbstractPublisher.hpp"

class HumidityPublisher : public AbstractPublisher<UvegHaz> {
public:
    HumidityPublisher();

    ~HumidityPublisher();

    void publish(bool scheduled, unsigned long until, unsigned long sentTS);
};


#endif //PROJECT_HUMIDITYPUBLISHER_HPP
