cmake_minimum_required(VERSION 3.10)
project(cs372-ufo)

set(CMAKE_CXX_STANDARD 17)

if( WIN32 )
    add_executable(ufo ufo.cpp file-folder.h retriever-win.cpp)
else()
    add_executable(ufo ufo.cpp file-folder.h)
endif()