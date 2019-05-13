// ufomain.cpp
// main function

#include "ufo.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using ufo::Ufo;

// Test folder: ..\our_directory_for_testing\ //

int main() {
    BoxPrint(2, "Welcome to UFO!");

    while(true) {
        string userInput;
        getline(cin, userInput);

        if (userInput.empty())
        {
            break;
        }
    }

    return 0;
}