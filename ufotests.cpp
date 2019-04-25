// ufotests.cpp
// For catch testing

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ufo.h"
#include <iostream>

// TODO:
// Test retrieval of a vector of WIN32_FIND_DATA
// - creation time
// - last access time
// - file size
// - file name
//

TEST_CASE("File Retrieval: Empty Path") {
    ufo::Ufo organizer;
    auto retrievedRootFolder = organizer.retrieve();

    REQUIRE(retrievedRootFolder[0].name == "CMakeCache.txt");
    REQUIRE(retrievedRootFolder[0].path.rfind(R"(\cmake-build-debug\CMakeCache.txt)") != string::npos);
}


TEST_CASE("File Retrieval: with path to file")
{
    ufo::Ufo organizer(
            R"(..\our_directory_for_testing\)");
    auto retrievedFolder = organizer.retrieve();
    auto path = retrievedFolder[0].path;
    auto name = retrievedFolder[0].name;
    auto size = retrievedFolder[0].size;
    auto dateCreated = retrievedFolder[0].dateCreated;
    auto dateModified = retrievedFolder[0].dateModified;
    REQUIRE( retrievedFolder[0].path.rfind(R"(\our_directory_for_testing\aura2_blue.png)") != string::npos );
}


TEST_CASE("Sorting")
{
    ufo::Ufo organizer(
            R"(..\our_directory_for_testing\)");

    SECTION("Sorting by file extension")
    {
        organizer.retrieve();
        organizer.sortFolder("extension");

        REQUIRE(!organizer.getfolder().folders.empty());
    }
}