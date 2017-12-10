//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_DECISIONPUBLISHER_HPP
#define PROJECT_DECISIONPUBLISHER_HPP

#include "DDS/Decision/common/Decision.hpp"
#include "DDS/AbstractPublisher.hpp"

class DecisionPublisher : public AbstractPublisher<DecisionInfo> {
public:
    DecisionPublisher();

    ~DecisionPublisher();

    void publish(bool scheduled, unsigned long until, unsigned long sentTS);
};


#endif //PROJECT_DECISIONPUBLISHER_HPP
