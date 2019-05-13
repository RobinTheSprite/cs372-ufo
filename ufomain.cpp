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
#include <sstream>
using std::stringstream;

// Test folder: ..\our_directory_for_testing\ //

int main() {
    BoxPrint(2, "Welcome to UFO!");

    while(true) {
        cout << endl;
        cout << "Type help for a list of commands or press [ENTER] to exit" << endl;

        string userInput;
        getline(cin, userInput);
        stringstream inputStream(userInput);
        string wordFromUserInput;

        inputStream >> wordFromUserInput;

        Ufo fileOrganizer;
        if (wordFromUserInput.empty())
        {
            break;
        }
        else if (wordFromUserInput == "organize")
        {
            inputStream >> wordFromUserInput;

        }
    }

    return 0;
}