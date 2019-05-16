// command.h
// Created by Mark on 5/16/2019.
//

#ifndef CS372_UFO_COMMAND_H
#define CS372_UFO_COMMAND_H

#include "ufo.h"
#include <memory>
#include <sstream>

class Command
{
  public:
    virtual ~Command() = default;
    virtual void execute() const =0;
  private:
};

class UfoOrganizeCommand : public Command
{
  public:
    explicit UfoOrganizeCommand(std::shared_ptr<ufo::Ufo> ufo,
                                std::shared_ptr<std::stringstream> inputStream);
    void execute();
  private:
    std::shared_ptr<ufo::Ufo> _ufoObject;
    std::shared_ptr<std::stringstream> _inputStream;
};


#endif //CS372_UFO_COMMAND_H
