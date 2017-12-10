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
};


#endif //PROJECT_DECISIONPUBLISHER_HPP
