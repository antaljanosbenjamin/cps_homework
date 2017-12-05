/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*****************************************************************************/

#ifndef __HELLO_PUBLISHER__
#define __HELLO_PUBLISHER__

#include <string>

class HelloPublisher {
public:
    /**
     * Creates the DDS entities for the publisher.
     * @param domain_id the domain ID.
     * @param verbose the verbose level.
     */
    HelloPublisher(int domain_id, const std::string& topic_name, bool verbose);

    /**
     * Publisher destructor
     */
    ~HelloPublisher();

    /**
     * Start sending the data.
     * @param data_sise size of the payload buffer to send.
     * @param sample_count the number of samples.
     */
    void publish(int data_size, int sample_count);

private:
    class HelloPublisherImpl;
    HelloPublisherImpl *impl;
};

#endif
