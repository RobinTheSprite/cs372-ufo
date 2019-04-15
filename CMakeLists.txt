cmake_minimum_required(VERSION 3.10)
project(cs372-ufo)

set(CMAKE_CXX_STANDARD 17)

if( WIN32 )
    add_executable(ufo ufo.cpp retriever-win.cpp)
else()
    add_executable(ufo ufo.cpp)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ufo ${SFML_LIBRARIES})
endif()