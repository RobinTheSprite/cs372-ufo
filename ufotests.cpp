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
    ufo::Ufo organizer("");
    auto retrievedRootFolder = organizer.retrieve();
}

// TODO: crashes when accessing a retrieved file's data members: "Process finished with exit code -1073741819 (0xC0000005)"
TEST_CASE("File Retrieval: with path to file")
{
    ufo::Ufo organizer("C:\\Users\\AlexL\\Documents\\UAF Classes\\Software Construction\\cs372-ufo\\our_directory_for_testing");
    auto retrievedFolder = organizer.retrieve();
   // auto path = retrievedFolder[0].path;
   // auto name = retrievedFolder[0].name;
   // auto size = retrievedFolder[0].size;
   // auto dateCreated = retrievedFolder[0].dateCreated;
   // auto dateModified = retrievedFolder[0].dateModified;

}
