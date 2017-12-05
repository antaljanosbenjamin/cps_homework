cmake_minimum_required(VERSION 2.8.11)
set( CMAKE_VERBOSE_MAKEFILE on )

set (CMAKE_CXX_FLAGS "--std=c++17 ${CMAKE_CXX_FLAGS} -DRTI_UNIX -DRTI_LINUX -DRTI_64BIT -DRTI_STATIC")

set(DDSHOME "$ENV{NDDSHOME}")
set(TARGET_ARCH "x64Linux3gcc5.4.0")

include_directories(${DDSHOME}/include ${DDSHOME}/include/ndds ${DDSHOME}/include/ndds/hpp)

link_directories(/home/kovi/bin/rti_connext_dds-5.3.0/lib/${TARGET_ARCH})

set(SOURCE_FILES HelloPublisher.cxx HelloSubscriber.cxx HelloWorld.cxx HelloWorldPlugin.cxx Hello.cxx )
set(HEADER_FILES HelloPublisher.hpp HelloSubscriber.hpp HelloWorld.hpp HelloWorldPlugin.hpp )

#message(SEND_ERROR "DDSHOME is ${DDSHOME}")

add_executable(HelloWorldRun ${SOURCE_FILES} ${HEADER_FILES} )


target_link_libraries(HelloWorldRun nddscpp2z nddscz nddscorez dl nsl m pthread rt)
