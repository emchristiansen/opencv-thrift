cmake_minimum_required(VERSION 2.8)

project(OpenCVThrift)

include(FindPkgConfig)
pkg_check_modules(thrift REQUIRED thrift)

find_package(OpenCV)

#We assume we're using Clang to build.

## SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

# All cpp files.
file(GLOB_RECURSE openCVSources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "OpenCV/**.cpp")
file(GLOB_RECURSE utilSources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "Util/**.cpp")

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS ${openCVSources} ${utilSources})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(OpenCVThrift ${openCVSources} ${utilSources})

target_link_libraries(OpenCVThrift ${thrift_LIBRARIES} ${OpenCV_LIBS})

#add_executable(Server "OpenCVServer.cpp")

#target_link_libraries(Server CPPInterface ${thrift_LIBRARIES} "-lpthread -lc++ -lsupc++")

################################
# Install
################################
# Configure "make install".
# In Linux this installs to /usr/local/include/salve/.
#install(
#  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/OpenCV/"
#  DESTINATION include/OpenCVThrift
#)

install(
  TARGETS OpenCVThrift DESTINATION lib
)

install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/OpenCV/"
  DESTINATION include/OpenCV
  PATTERN "*.cpp" EXCLUDE
)
