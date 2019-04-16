cmake_minimum_required(VERSION 3.10)
project(cs372-ufo)

set(CMAKE_CXX_STANDARD 17)

if( WIN32 )
    add_executable(ufo ufomain.cpp retriever-win.cpp ufo.cpp ufo.h)
    add_executable(ufotests ufotests.cpp ufo.cpp ufo.h retriever-win.cpp)
else()
    add_executable(ufo ufomain.cpp ufo.cpp ufo.h file-folder.h)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ufo ${SFML_LIBRARIES})
endif()