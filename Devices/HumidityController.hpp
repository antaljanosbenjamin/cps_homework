//
// Created by kovi on 12/10/17.
//

#ifndef PROJECT_HUMIDITYCONTROLLER_HPP
#define PROJECT_HUMIDITYCONTROLLER_HPP


class HumidityController {
private:
    std::unique_ptr<WeatherSubscriber> weatherSubscriber;
    std::unique_ptr<ScheduleSubscriber> scheduleSubscriber;
    std::unique_ptr<ConfigSubscriber> configSubscriber;
};


#endif //PROJECT_HUMIDITYCONTROLLER_HPP
