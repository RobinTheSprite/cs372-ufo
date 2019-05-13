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
    virtual void execute() =0;
  private:
};

class UfoCommand : public Command
{
  public:
    explicit UfoCommand(ufo::Ufo &ufo,
                        std::stringstream &inputStream);

  protected:
    ufo::Ufo * _ufoObject;
    std::stringstream * _inputStream;
};

class UfoOrganizeCommand : public UfoCommand
{
  public:
    using UfoCommand::UfoCommand;
    void execute() override;
  private:
};

class UfoCdCommand : public UfoCommand
{
  public:
    using UfoCommand::UfoCommand;
    void execute() override;
  private:
};

class UfoLsCommand : public UfoCommand
{
  public:
    using UfoCommand::UfoCommand;
    void execute() override;
  private:
};


#endif //CS372_UFO_COMMAND_H
