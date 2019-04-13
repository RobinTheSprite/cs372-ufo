// ufotests.cpp
// For catch testing

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ufo.h"

// TODO:
// Test retrieval of a vector of WIN32_FIND_DATA
// - creation time
// - last access time
// - file size
// - file name
//

TEST_CASE("File Retrieval")
{
    ufo::Ufo organizer("");
    organizer.retrieve();
}