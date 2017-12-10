//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_CONFIGSUBSCRIBER_HPP
#define PROJECT_CONFIGSUBSCRIBER_HPP

#include "DDS/AbstractSubscriber.hpp"
#include "DDS/Config/common/Config.hpp"

class ConfigSubscriber  : public AbstractSubscriber<Config> {
public:

    ConfigSubscriber();

    ~ConfigSubscriber() override;

    void receiveData( const Config & data);
};


#endif //PROJECT_CONFIGSUBSCRIBER_HPP
