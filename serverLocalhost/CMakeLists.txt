cmake_minimum_required(VERSION 2.8)

project(OpenCVThriftServerLocalhost)

include(FindPkgConfig)
pkg_check_modules(thrift REQUIRED thrift)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../implementation/OpenCVThrift")
file(GLOB_RECURSE implementationSources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "../implementation/OpenCVThrift/**.cpp")
message(STATUS ${implementationSources})

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

add_executable(OpenCVThriftServerLocalhost "OpenCVServer.cpp" ${implementationSources})

#target_link_libraries(OpenCVThriftServerLocalhost ${OpenCV_LIBS} ${thrift_LIBRARIES} "-lOpenCVThrift -lpthread -lc++ -lsupc++")
target_link_libraries(OpenCVThriftServerLocalhost ${OpenCV_LIBS} ${thrift_LIBRARIES})

#target_link_libraries(Server CPPInterface ${thrift_LIBRARIES} "-lpthread -lc++ -lsupc++")

