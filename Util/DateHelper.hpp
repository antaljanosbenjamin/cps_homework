//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_DATEHELPER_HPP
#define PROJECT_DATEHELPER_HPP

class DateHelper {
public:
    static const boost::posix_time::ptime epoch;

    static boost::posix_time::ptime toPTime(unsigned long unixtimestamp){
        return epoch + boost::posix_time::seconds(unixtimestamp);
    }

    static unsigned long  toUnixTimestamp(const boost::posix_time::ptime & time){
        return (time - epoch).total_seconds();
    }

};

const boost::posix_time::ptime DateHelper::epoch(boost::gregorian::date(1970, 1, 1));
#endif //PROJECT_DATEHELPER_HPP
