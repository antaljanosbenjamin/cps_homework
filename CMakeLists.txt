cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set (CMAKE_CXX_FLAGS "--std=c++14 ${CMAKE_CXX_FLAGS} -DRTI_UNIX -DRTI_LINUX -DRTI_64BIT -DRTI_STATIC -DBOOST_LOG_DYN_LINK")

set(DDSHOME "/home/kovi/bin/rti_connext_dds-5.3.0/")
set(TARGET_ARCH "x64Linux3gcc5.4.0")

include_directories(${DDSHOME}/include ${DDSHOME}/include/ndds ${DDSHOME}/include/ndds/hpp)

link_directories(${DDSHOME}lib/${TARGET_ARCH})

# WEATHER
include_directories(".")

set(WEATHER_COMMON_SOURCES Weather/common/Weather.cxx Weather/common/WeatherPlugin.cxx)
set(WEATHER_COMMON_HEADERS Weather/common/Weather.hpp Weather/common/WeatherPlugin.hpp)

set(WEATHER_PUB_SOURCES Weather/publisher/WeatherPublisher.cpp)
set(WEATHER_PUB_HEADERS Weather/publisher/WeatherPublisher.hpp)

set(WEATHER_SUB_SOURCES Weather/subscriber/WeatherSubscriber.cpp)
set(WEATHER_SUB_HEADERS Weather/subscriber/WeatherSubscriber.hpp)

set(WEATHER_ALL ${WEATHER_COMMON_SOURCES}
                ${WEATHER_COMMON_HEADERS}
                ${WEATHER_PUB_SOURCES}
                ${WEATHER_PUB_HEADERS}
                ${WEATHER_SUB_SOURCES}
                ${WEATHER_SUB_HEADERS})

# AzureWrapper
set(AZUREIOT_INC_FOLDER ".." "/usr/include/azureiot" "/usr/include/azureiot/inc")
set(RAPIDJSON_INC_FOLDER "/home/kovi/Repos/rapidjson/include")

set(AZURE_WRAPPER_SOURCES "AzureWrapper/IoTHubClient.cpp")
set(AZURE_WRAPPER_HEADERS "AzureWrapper/IoTHubClient.hpp")

set(AZURE_WRAPPER_ALL ${AZURE_WRAPPER_SOURCES} ${AZURE_WRAPPER_HEADERS})


find_package(Boost REQUIRED COMPONENTS date_time log log_setup )

include_directories(${AZUREIOT_INC_FOLDER} ${RAPIDJSON_INC_FOLDER} ${Boost_INCLUDE_DIRS})

# Final target
add_executable(cps_main ${WEATHER_ALL} ${AZURE_WRAPPER_ALL} main.cpp)
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
        ssl
        crypto
        m
        uuid
        ${Boost_LIBRARIES}
        )
