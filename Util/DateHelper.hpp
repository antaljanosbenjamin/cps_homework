//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_DATEHELPER_HPP
#define PROJECT_DATEHELPER_HPP

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time_adjustor.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>

class DateHelper {
public:
    static boost::posix_time::ptime toPTime(std::time_t unixtimestamp) {
        return boost::posix_time::from_time_t(unixtimestamp);
    }

    static std::time_t toUnixTimestamp(const boost::posix_time::ptime &time) {
        return boost::posix_time::to_time_t(time);
    }

};

#endif //PROJECT_DATEHELPER_HPP
