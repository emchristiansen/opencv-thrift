cmake_minimum_required(VERSION 2.8)

project(OpenCVThrift)

include(FindPkgConfig)
pkg_check_modules(thrift REQUIRED thrift)

## SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

# All cpp files.
file(GLOB_RECURSE sources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "modules/**.cpp")

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS ${sources})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(CPPInterface ${sources})

target_link_libraries(CPPInterface ${thrift_LIBRARIES})

add_executable(Server "OpenCVServer.cpp")

target_link_libraries(Server CPPInterface ${thrift_LIBRARIES} "-lpthread -lc++ -lsupc++")

