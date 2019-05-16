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
#include <memory>
#include <algorithm>
#include "ufo.h"

// Test folder: ..\our_directory_for_testing\ //

int main()
{
    BoxPrint(2, "Welcome to UFO!");

    Ufo fileOrganizer;
    while (true)
    {
        cout << endl;
        cout << "Type help for a list of commands or press [ENTER] to exit: ";

        string userInput;
        getline(cin, userInput);
        stringstream inputStream(userInput);
        string wordFromUserInput;

        inputStream >> wordFromUserInput;

        if (wordFromUserInput.empty())
        {
            break;
        }
        else if (wordFromUserInput == "organize")
        {
            inputStream >> wordFromUserInput;
            fileOrganizer.setRoot(wordFromUserInput);

            inputStream >> wordFromUserInput;
            fileOrganizer.sortFolder(wordFromUserInput);
        }
        else if (wordFromUserInput == "cd")
        {
            inputStream >> wordFromUserInput;
            if (wordFromUserInput == "..")
            {
                fileOrganizer.moveCurrFolderUp();
            }
            else
            {
                fileOrganizer.moveCurrFolderDown(wordFromUserInput);
            }
        }
        else if (wordFromUserInput == "ls")
        {
            for (const auto &folder : fileOrganizer.getCurrentFolder().folders)
            {
                cout << folder->name << endl;
            }

            for (const auto &file : fileOrganizer.getCurrentFolder().files)
            {
                cout << file.name << endl;
            }
        }
    }

    return 0;
}