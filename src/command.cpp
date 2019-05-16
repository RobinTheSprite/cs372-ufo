// command.cpp
// Created by Mark on 5/16/2019.
//

#include "command.h"
#include <string>

UfoOrganizeCommand::UfoOrganizeCommand(std::shared_ptr<ufo::Ufo> ufo,
                                       std::shared_ptr<std::stringstream> inputStream)
: _ufoObject{std::move(ufo)}, _inputStream{std::move(inputStream)}
{}

void UfoOrganizeCommand::execute()
{
    std::string wordFromUserInput;
    *_inputStream >> wordFromUserInput;
    _ufoObject->setRoot(wordFromUserInput);

    *_inputStream >> wordFromUserInput;
    _ufoObject->sortFolder(wordFromUserInput);
}
