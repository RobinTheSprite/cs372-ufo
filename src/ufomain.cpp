// ufomain.cpp
// main function

#include "ufo.h"
using ufo::Ufo;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include "command.h"

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

        std::map<string, std::unique_ptr<Command>> commands;
        commands.insert({"organize", std::make_unique<UfoOrganizeCommand>(fileOrganizer, inputStream)});
        commands.insert({"cd", std::make_unique<UfoCdCommand>(fileOrganizer, inputStream)});
        commands.insert({"ls", std::make_unique<UfoLsCommand>(fileOrganizer, inputStream)});

        inputStream >> wordFromUserInput;

        if (wordFromUserInput.empty())
        {
            break;
        }
        else if (commands.count(wordFromUserInput) != 0)
        {
            commands.at(wordFromUserInput)->execute();
        }
    }

    return 0;
}