//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_ABSTRACTPUBLISHER_HPP
#define PROJECT_ABSTRACTPUBLISHER_HPP

#include <string>
#include <dds/dds.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

template<typename DataT>
class AbstractPublisher {
public:
    AbstractPublisher(int domain_id, const std::string &topic_name) :
            participant(domain_id),
            topic(participant, topic_name),
            writer(dds::pub::Publisher(participant), topic) {
    }

    virtual ~AbstractPublisher() {}

    void publishData(const DataT &data) {
        // Write samples from the instance
        BOOST_LOG_TRIVIAL(debug) << "Sending data...";
        int errorCount = 0;
        int success = false;
        while (!success && errorCount < MaxConsecutiveWriteErrors) {

            try {
                writer.write(data);
                BOOST_LOG_TRIVIAL(debug) << "Success!";
                success = true;
            } catch (const dds::core::TimeoutError &error) {
                BOOST_LOG_TRIVIAL(error) << error.what();
                errorCount++;
                if (errorCount == MaxConsecutiveWriteErrors) {
                    BOOST_LOG_TRIVIAL(error) << "Reached maximum number of failure!";
                    break;
                }
            }
            rti::util::sleep(dds::core::Duration::from_millisecs(500));
        }

        writer.wait_for_acknowledgments(dds::core::Duration::from_secs(10));

    }

private:
    static const int MaxConsecutiveWriteErrors = 10;
    dds::domain::DomainParticipant participant;
    dds::topic::Topic<DataT> topic;
    dds::pub::DataWriter<DataT> writer;
};


#endif //PROJECT_ABSTRACTPUBLISHER_HPP
