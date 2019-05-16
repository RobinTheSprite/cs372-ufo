// command.cpp
// Created by Mark on 5/16/2019.
//

#include "command.h"
#include <string>

UfoOrganizeCommand::UfoOrganizeCommand(ufo::Ufo &ufo,
                                       std::stringstream &inputStream)
: _ufoObject{std::make_shared<ufo::Ufo>(ufo)}, _inputStream{&inputStream}
{}

void UfoOrganizeCommand::execute()
{
    std::string wordFromUserInput;
    *_inputStream >> wordFromUserInput;
    _ufoObject->setRoot(wordFromUserInput);

    *_inputStream >> wordFromUserInput;
    _ufoObject->sortFolder(wordFromUserInput);
}
