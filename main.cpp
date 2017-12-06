//
// Created by kovi on 12/6/17.
//

#include "WeatherPublisher.hpp"
#include "WeatherSubscriber.hpp"

int main(int argc, const char **argv)
{
    if (argc < 2){
        return -1;
    }

    if (argv[1][0] == 'p'){
        WeatherPublisher pub(0, "weather");
        pub.publish(50);
    } else if (argv[1][0] == 's'){
        WeatherSubscriber sub(0, "weather");
        sub.startReceiving();
    }
    dds::domain::DomainParticipant::finalize_participant_factory();
}
