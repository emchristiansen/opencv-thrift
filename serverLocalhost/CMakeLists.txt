cmake_minimum_required(VERSION 2.8)

project(OpenCVThriftServerLocalhost)

#include("../implementation")

include(FindPkgConfig)
pkg_check_modules(thrift REQUIRED thrift)

find_package(OpenCV REQUIRED)

## SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# All cpp files.
#file(GLOB_RECURSE sources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "OpenCV/**.cpp")

#include("../implementation")
#ExternalProject_Add(OpenCVThrift
#                    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../implementation)

#message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
#message(STATUS ${sources})
message(STATUS ${OpenCV_LIBS})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#add_library(CPPInterface ${sources})

#target_link_libraries(CPPInterface ${thrift_LIBRARIES})

add_executable(OpenCVThriftServerLocalhost "OpenCVServer.cpp")

#target_link_libraries(OpenCVThriftServerLocalhost ${OpenCV_LIBS} ${thrift_LIBRARIES} "-lOpenCVThrift -lpthread -lc++ -lsupc++")
target_link_libraries(OpenCVThriftServerLocalhost ${OpenCV_LIBS} ${thrift_LIBRARIES} "-lOpenCVThrift")

#target_link_libraries(Server CPPInterface ${thrift_LIBRARIES} "-lpthread -lc++ -lsupc++")

