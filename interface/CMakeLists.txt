cmake_minimum_required(VERSION 2.8)

project(OpenCVThrift)

include(FindPkgConfig)
pkg_check_modules(thrift REQUIRED thrift)

# All cpp files.
file(GLOB_RECURSE sources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "modules/**.cpp")

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS ${sources})

add_library(CPPInterface ${sources})

target_link_libraries(CPPInterface ${thrift_LIBRARIES})

