cmake_minimum_required(VERSION 3.5.1)
# This file is based on the following files/articles:
# https://github.com/Azure/azure-iot-sdk-c/blob/master/doc/ubuntu_apt-get_sample_setup.md
# https://github.com/Tencent/rapidjson/
# Example make file of RTI Connext DDS rti_workspace/5.3.0/examples/connext_dds/c++11/hello_idl/make/makefile_Hello_x64Linux3gcc5.4.0
# and of course a lot of stackoverflow answer

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_FLAGS "--std=c++17 ${CMAKE_CXX_FLAGS} -DRTI_UNIX -DRTI_LINUX -DRTI_64BIT -DRTI_STATIC -DBOOST_LOG_DYN_LINK -Wall")

# DDS
set(DDSHOME $ENV{NDDSHOME})
set(TARGET_ARCH "x64Linux3gcc5.4.0")

include_directories(SYSTEM ${DDSHOME}/include ${DDSHOME}/include/ndds ${DDSHOME}/include/ndds/hpp)

link_directories(${DDSHOME}/lib/${TARGET_ARCH})

set(DDS_SOURCES DDS/AbstractPublisher.hpp DDS/AbstractSubscriber.hpp)

# WEATHER
set(WEATHER_COMMON_SOURCES DDS/Weather/common/Weather.cxx DDS/Weather/common/WeatherPlugin.cxx)
set(WEATHER_COMMON_HEADERS DDS/Weather/common/Weather.hpp DDS/Weather/common/WeatherPlugin.hpp)

set(WEATHER_PUB_SOURCES ${DDS_SOURCES} DDS/Weather/publisher/WeatherPublisher.cpp)
set(WEATHER_PUB_HEADERS DDS/Weather/publisher/WeatherPublisher.hpp)

set(WEATHER_SUB_SOURCES DDS/Weather/subscriber/WeatherSubscriber.cpp)
set(WEATHER_SUB_HEADERS DDS/Weather/subscriber/WeatherSubscriber.hpp)

set(WEATHER_ALL_SOURCES ${WEATHER_COMMON_SOURCES}
        ${WEATHER_PUB_SOURCES}
        ${WEATHER_SUB_SOURCES})

# SCHEDULE
set(SCHEDULE_COMMON_SOURCES DDS/Schedule/common/Schedule.cxx DDS/Schedule/common/SchedulePlugin.cxx)
set(SCHEDULE_COMMON_HEADERS DDS/Schedule/common/Schedule.hpp DDS/Schedule/common/SchedulePlugin.hpp)

set(SCHEDULE_PUB_SOURCES ${DDS_SOURCES} DDS/Schedule/publisher/SchedulePublisher.cpp)
set(SCHEDULE_PUB_HEADERS DDS/Schedule/publisher/SchedulePublisher.hpp)

set(SCHEDULE_SUB_SOURCES DDS/Schedule/subscriber/ScheduleSubscriber.cpp)
set(SCHEDULE_SUB_HEADERS DDS/Schedule/subscriber/ScheduleSubscriber.hpp)

set(SCHEDULE_ALL_SOURCES ${SCHEDULE_COMMON_SOURCES}
        ${SCHEDULE_PUB_SOURCES}
        ${SCHEDULE_SUB_SOURCES})

# CONFIG
set(CONFIG_COMMON_SOURCES DDS/Config/common/Config.cxx DDS/Config/common/ConfigPlugin.cxx)
set(CONFIG_COMMON_HEADERS DDS/Config/common/Config.hpp DDS/Config/common/ConfigPlugin.hpp)

set(CONFIG_PUB_SOURCES ${DDS_SOURCES} DDS/Config/publisher/ConfigPublisher.cpp)
set(CONFIG_PUB_HEADERS DDS/Config/publisher/ConfigPublisher.hpp)

set(CONFIG_SUB_SOURCES DDS/Config/subscriber/ConfigSubscriber.cpp)
set(CONFIG_SUB_HEADERS DDS/Config/subscriber/ConfigSubscriber.hpp)

set(CONFIG_ALL_SOURCES ${CONFIG_COMMON_SOURCES}
        ${CONFIG_PUB_SOURCES}
        ${CONFIG_SUB_SOURCES})

# DECISION
set(DECISION_COMMON_SOURCES DDS/Decision/common/Decision.cxx DDS/Decision/common/DecisionPlugin.cxx)
set(DECISION_COMMON_HEADERS DDS/Decision/common/Decision.hpp DDS/Decision/common/DecisionPlugin.hpp)

set(DECISION_PUB_SOURCES ${DDS_SOURCES} DDS/Decision/publisher/DecisionPublisher.cpp)
set(DECISION_PUB_HEADERS DDS/Decision/publisher/DecisionPubDownload and install lisher.hpp)

set(DECISION_SUB_SOURCES DDS/Decision/subscriber/DecisionSubscriber.cpp)
set(DECISION_SUB_HEADERS DDS/Decision/subscriber/DecisionSubscriber.hpp)

# fix for includes in DDS/Decision/common/Decision.hpp
set(DECISION_ADDITIONAL_INCLUDE_DIRS DDS/Config/common DDS/Schedule/common DDS/Humidity/common DDS/Weather/common)
include_directories(${DECISION_ADDITIONAL_INCLUDE_DIRS})

set(DECISION_ALL_SOURCES ${DECISION_COMMON_SOURCES}
        ${DECISION_PUB_SOURCES}
        ${DECISION_SUB_SOURCES})

# HUMIDITY
set(HUMIDITY_COMMON_SOURCES DDS/Humidity/common/UvegHaz.cxx DDS/Humidity/common/UvegHazPlugin.cxx)
set(HUMIDITY_COMMON_HEADERS DDS/Humidity/common/UvegHaz.hpp DDS/Humidity/common/UvegHazPlugin.hpp)

set(HUMIDITY_PUB_SOURCES ${DDS_SOURCES} DDS/Humidity/publisher/HumidityPublisher.cpp)
set(HUMIDITY_PUB_HEADERS DDS/Humidity/publisher/HumidityPublisher.hpp)

set(HUMIDITY_SUB_SOURCES DDS/Humidity/subscriber/HumiditySubscriber.cpp)
set(HUMIDITY_SUB_HEADERS DDS/Humidity/subscriber/HumiditySubscriber.hpp)

set(HUMIDITY_ALL_SOURCES ${HUMIDITY_COMMON_SOURCES}
        ${HUMIDITY_PUB_SOURCES}
        ${HUMIDITY_SUB_SOURCES})

# AzureWrapper
set(AZUREIOT_INC_FOLDER ".." "/usr/local/include/azureiot" "/usr/local/include/azureiot/inc")
find_package(RapidJSON)

set(AZURE_WRAPPER_SOURCES "AzureWrapper/IoTHubClient.cpp")
set(AZURE_WRAPPER_HEADERS "AzureWrapper/IoTHubClient.hpp")

set(AZURE_WRAPPER_ALL_SOURCES ${AZURE_WRAPPER_SOURCES})

find_package(Boost REQUIRED COMPONENTS date_time log log_setup)

include_directories(SYSTEM ${AZUREIOT_INC_FOLDER} ${RAPIDJSON_INC_FOLDER})

# CURLPP
include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)

# UTIL STUFF
set(UTIL_SOURCES "Util/WeatherInformationService.cpp" "Util/DateHelper.cpp")

# EDGE STUFF
set(EDGE_SOURCES "Devices/HumidityEdge.cpp")

# CONTROLLER STUFF
set(CONTROLLER_SOURCES "Devices/HumidityController.cpp")

# Final target
include_directories(".")
add_executable(cps_main ${WEATHER_ALL_SOURCES} ${AZURE_WRAPPER_ALL_SOURCES} ${UTIL_SOURCES} ${EDGE_SOURCES} 
        ${SCHEDULE_ALL_SOURCES} ${CONFIG_ALL_SOURCES} ${DECISION_ALL_SOURCES} ${HUMIDITY_ALL_SOURCES} ${CONTROLLER_SOURCES} main.cpp)
target_link_libraries(cps_main
        nddscpp2z
        nddscz
        nddscorez
        dl
        nsl
        pthread
        rt
        serializer
        iothub_client
        iothub_client_amqp_transport
        aziotsharedutil
        uamqp
        pthread
        curl
        curlpp
        ssl
        crypto
        m
        uuid
        ${Boost_LIBRARIES}
        ${CURLPP_LDFLAGS}
        )
