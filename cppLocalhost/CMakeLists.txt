cmake_minimum_required(VERSION 2.8)

project(OpenCVThriftLocalhost)

include(FindPkgConfig)
pkg_check_modules(thrift REQUIRED thrift)

find_package(OpenCV)

## SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Complain if we have undefined references when linking.
# Otherwise we can get silently propagating link errors.
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")

# We grab the client headers and sources from our sister directory.
# It would probably be better if we did some kind of CMake multi-project
# configuration instead.
set(CLIENT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../cpp/OpenCVThrift/")
message(STATUS $CLIENT_ROOT)
include_directories(${CLIENT_ROOT})
file(GLOB_RECURSE clientSources RELATIVE "${CLIENT_ROOT}" "**.cpp")

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS ${clientSources})

# Build the localhost library.
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib")
file(GLOB_RECURSE libSources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "**.cpp")
add_library(OpenCVThriftLocalhost SHARED ${clientSources} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(OpenCVThriftLocalhost ${thrift_LIBRARIES} ${OpenCV_LIBS})

