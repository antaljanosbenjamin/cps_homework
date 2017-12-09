cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set (CMAKE_CXX_FLAGS "--std=c++17 ${CMAKE_CXX_FLAGS} -DRTI_UNIX -DRTI_LINUX -DRTI_64BIT -DRTI_STATIC -DBOOST_LOG_DYN_LINK -Wall")

set(DDSHOME "/home/kovi/bin/rti_connext_dds-5.3.0/")
set(TARGET_ARCH "x64Linux3gcc5.4.0")

include_directories(SYSTEM ${DDSHOME}/include ${DDSHOME}/include/ndds ${DDSHOME}/include/ndds/hpp)

link_directories(${DDSHOME}lib/${TARGET_ARCH})

# WEATHER
include_directories(".")

set(WEATHER_COMMON_SOURCES DDS/Weather/common/Weather.cxx DDS/Weather/common/WeatherPlugin.cxx)
set(WEATHER_COMMON_HEADERS DDS/Weather/common/Weather.hpp DDS/Weather/common/WeatherPlugin.hpp)

set(WEATHER_PUB_SOURCES DDS/Weather/publisher/WeatherPublisher.cpp)
set(WEATHER_PUB_HEADERS DDS/Weather/publisher/WeatherPublisher.hpp)

set(WEATHER_SUB_SOURCES DDS/Weather/subscriber/WeatherSubscriber.cpp)
set(WEATHER_SUB_HEADERS DDS/Weather/subscriber/WeatherSubscriber.hpp)

set(WEATHER_ALL_SOURCES ${WEATHER_COMMON_SOURCES}
                        ${WEATHER_PUB_SOURCES}
                        ${WEATHER_SUB_SOURCES})

# AzureWrapper
set(AZUREIOT_INC_FOLDER ".." "/usr/include/azureiot" "/usr/include/azureiot/inc")
set(RAPIDJSON_INC_FOLDER "/home/kovi/Repos/rapidjson/include")

set(AZURE_WRAPPER_SOURCES "AzureWrapper/IoTHubClient.cpp")
set(AZURE_WRAPPER_HEADERS "AzureWrapper/IoTHubClient.hpp")

set(AZURE_WRAPPER_ALL_SOURCES ${AZURE_WRAPPER_SOURCES})

find_package(Boost REQUIRED COMPONENTS date_time log log_setup )

include_directories(SYSTEM ${AZUREIOT_INC_FOLDER} ${RAPIDJSON_INC_FOLDER} ${Boost_INCLUDE_DIRS})

# CURLPP https://github.com/jpbarrette/curlpp
# after install run cp /usr/local/lib/libcurlpp.* /usr/lib/
include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)

# UTIL STUFF
set(UTIL_SOURCES "Util/WeatherInformationService.cpp")

# Final target
add_executable(cps_main ${WEATHER_ALL_SOURCES} ${AZURE_WRAPPER_ALL_SOURCES} ${UTIL_SOURCES} main.cpp)
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
        ${CURLPP_LDFLAGS}
        )
