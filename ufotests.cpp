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

TEST_CASE("File Retrieval: Empty Path") {
    ufo::Ufo organizer("");
    auto retrievedRootFolder = organizer.retrieve();
}

// TODO:
// fix "Error: The system cannot find the path specified." and
// "FAILED: due to unexpected exception with message: std::bad_alloc"
TEST_CASE("File Retrieval: with path to file")
{
    ufo::Ufo organizer("C:\\Users\\AlexL\\Documents\\UAF Classes\\Software Construction\\cs372-ufo\\our_directory_for_testing\\license.txt");
    auto retrievedFile = organizer.retrieve();

}

