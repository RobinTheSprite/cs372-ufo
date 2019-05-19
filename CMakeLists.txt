cmake_minimum_required(VERSION 3.10)
project(cs372-ufo)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES src/*.cpp)
file(GLOB SOURCES-WIN src/windows/*.cpp)

if( WIN32 )
    add_executable(ufo ${SOURCES} ${SOURCES-WIN})
    add_executable(ufotests ufotests.cpp ${SOURCES} ${SOURCES-WIN})
else()
    add_executable(ufo ${SOURCES})
endif()

target_include_directories(ufo PRIVATE include)