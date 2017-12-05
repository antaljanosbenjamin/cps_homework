/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

#ifndef __HELLO_SUBSCRIBER__
#define __HELLO_SUBSCRIBER__

#include <string>

class HelloSubscriber {
public:
    /**
     * Creates the DDS entities for the subscriber.
     * @param domain_id the domain ID.
     * @param sample_count the number of samples to receive.
     */
    HelloSubscriber(
            int domain_id,
            const std::string& topic_name,
            bool verbose,
            int sample_count);

    /**
     * Subscriber destructor
     */
    ~HelloSubscriber();

    /**
     * Start receiving the data.
     */
    void receive();

private:
    class HelloSubscriberImpl;
    HelloSubscriberImpl *impl;
};

#endif
