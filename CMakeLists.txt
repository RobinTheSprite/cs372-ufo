cmake_minimum_required(VERSION 3.10)
project(cs372-ufo)

set(CMAKE_CXX_STANDARD 17)

if( WIN32 )
    add_executable(ufo ufomain.cpp retriever-win.cpp open-win.cpp ufo.cpp ufo.h)
    add_executable(ufotests ufotests.cpp ufo.cpp ufo.h retriever-win.cpp open-win.cpp)
else()
    add_executable(ufo ufomain.cpp ufo.cpp ufo.h file-folder.h)
endif()
