cmake_minimum_required(VERSION 2.8)

project(OpenCVThrift)

include(FindPkgConfig)
pkg_check_modules(thrift REQUIRED thrift)

# All cpp files in gen-cpp.
file(GLOB thriftSources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "interface/*cpp")

add_library(CPPInterface ${thriftSources})

target_link_libraries(CPPInterface ${thrift_LIBRARIES})

