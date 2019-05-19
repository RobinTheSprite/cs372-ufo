// command.cpp
// Created by Mark on 5/16/2019.
//

#include "command.h"
#include <string>

UfoCommand::UfoCommand(ufo::Ufo &ufo, std::stringstream &inputStream)
        : _ufoObject{&ufo}, _inputStream{&inputStream}
{}

void UfoOrganizeCommand::execute()
{
    std::string wordFromUserInput;
    *_inputStream >> wordFromUserInput;
    _ufoObject->setRoot(wordFromUserInput);

    *_inputStream >> wordFromUserInput;
    _ufoObject->sortFolder(wordFromUserInput);
}

void UfoCdCommand::execute()
{
    std::string wordFromUserInput;
    *_inputStream >> wordFromUserInput;
    if (wordFromUserInput == "..")
    {
        _ufoObject->moveCurrFolderUp();
    }
    else
    {
        _ufoObject->moveCurrFolderDown(wordFromUserInput);
    }
}

void UfoLsCommand::execute()
{
    for (const auto &folder : _ufoObject->getCurrentFolder().folders)
    {
        cout << folder.first << endl;
    }

    for (const auto &file : _ufoObject->getCurrentFolder().files)
    {
        cout << file.name << endl;
    }
}
