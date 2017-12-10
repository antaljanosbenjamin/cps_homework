//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_DECISIONSUBSCRIBER_HPP
#define PROJECT_DECISIONSUBSCRIBER_HPP

#include "DDS/AbstractSubscriber.hpp"
#include "DDS/Decision/common/Decision.hpp"

class DecisionSubscriber  : public AbstractSubscriber<DecisionInfo> {
public:

    DecisionSubscriber();

    ~DecisionSubscriber() override;
};


#endif //PROJECT_DECISIONSUBSCRIBER_HPP
