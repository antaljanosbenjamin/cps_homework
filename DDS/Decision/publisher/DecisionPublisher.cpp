//
// Created by kovi on 12/10/17.
//

#include <iostream>
#include <string>
#include <dds/dds.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "DecisionPublisher.hpp"

using namespace dds::core;
using namespace dds::domain;
using namespace dds::topic;
using namespace dds::pub;

DecisionPublisher::
DecisionPublisher() :
        AbstractPublisher(42,"decision_info") {
}

DecisionPublisher::~DecisionPublisher() {
}