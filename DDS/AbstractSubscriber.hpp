//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_ABSTRACTSUBSCRIBER_HPP
#define PROJECT_ABSTRACTSUBSCRIBER_HPP

#include <string>
#include <dds/dds.hpp>
#include <atomic>

template<typename DataT>
class AbstractSubscriber : public dds::sub::NoOpDataReaderListener<DataT> {
public:

    AbstractSubscriber(int domain_id, const std::string &topic_name, int pollSeconds) :
            participant(domain_id),
            topic(participant, topic_name),
            reader(dds::sub::Subscriber(participant), topic),
            pollSeconds(pollSeconds) {
        reader.listener(this, dds::core::status::StatusMask::all());
    }

    virtual ~AbstractSubscriber() {
        reader.listener(NULL, dds::core::status::StatusMask::none());
    }

    void on_data_available(dds::sub::DataReader<DataT> &reader) override {
        dds::sub::LoanedSamples<DataT> samples = reader.take();
        for (typename dds::sub::LoanedSamples<DataT>::iterator it = samples.begin(); it != samples.end(); it++) {
            std::cout << "Data received!" << std::endl;
            if (it->info().valid()) {
                std::cout << "Data received!";
            }
        }
    }

    virtual void receiveData(const DataT &data) = 0;

    void startReceiving() {
        while (true) {
            rti::util::sleep(dds::core::Duration::from_secs(pollSeconds.load()));
        }
    }

    void stopReceiving() {
        reader.listener(NULL, dds::core::status::StatusMask::none());
    }

private:
    dds::domain::DomainParticipant participant;
    dds::topic::Topic<DataT> topic;
    dds::sub::DataReader<DataT> reader;

    std::atomic<int> pollSeconds;
};

#endif //PROJECT_ABSTRACTSUBSCRIBER_HPP
