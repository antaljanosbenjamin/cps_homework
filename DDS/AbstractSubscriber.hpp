//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_ABSTRACTSUBSCRIBER_HPP
#define PROJECT_ABSTRACTSUBSCRIBER_HPP

#include <string>
#include <dds/dds.hpp>
#include <atomic>
#include <thread>

template<typename DataT>
class AbstractSubscriber : public dds::sub::NoOpDataReaderListener<DataT> {
public:

    AbstractSubscriber(int domain_id, const std::string &topic_name, int pollSeconds) :
            participant(domain_id),
            topic(participant, topic_name),
            reader(dds::sub::Subscriber(participant), topic),
            pollSeconds(pollSeconds),
            receiverThread(){
        this->reader.listener(this, dds::core::status::StatusMask::none());
    }

    virtual ~AbstractSubscriber() {
        reader.listener(NULL, dds::core::status::StatusMask::none());
    }

    void on_data_available(dds::sub::DataReader<DataT> &reader) override {
        dds::sub::LoanedSamples<DataT> samples = reader.take();
        for (typename dds::sub::LoanedSamples<DataT>::iterator it = samples.begin(); it != samples.end(); it++) {
            if (it->info().valid()) {
                consumerFunction(it->data());
            }
        }
    }

    void startReceiving(std::function<void(const DataT& data)> consumerFunction) {
        this->consumerFunction = consumerFunction;
        this->reader.listener(this, dds::core::status::StatusMask::all());
        this->receiverThread = std::thread([this](){
            while (true) {
                rti::util::sleep(dds::core::Duration::from_secs(this->pollSeconds.load()));
            }
        });
    }

    void stopReceiving() {
        this->reader.listener(NULL, dds::core::status::StatusMask::none());
        if (this->receiverThread.joinable()){
            this->receiverThread.join();
        }
    }

private:
    dds::domain::DomainParticipant participant;
    dds::topic::Topic<DataT> topic;
    dds::sub::DataReader<DataT> reader;
    std::function<void(const DataT& data)> consumerFunction;
    std::atomic<int> pollSeconds;
    std::thread receiverThread;
};

#endif //PROJECT_ABSTRACTSUBSCRIBER_HPP
