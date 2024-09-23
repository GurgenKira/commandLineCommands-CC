#ifndef __COMMANDLINE_COMMANDS_COMMAND_MANAGER_HPP__
#define __COMMANDLINE_COMMANDS_COMMAND_MANAGER_HPP__

#include "commands.hpp"

#include <memory>

class commandManager
{
public:
    commandManager(int argc, char** argv);

    void run();

private:
    std::unique_ptr<command> m_currentCommand;
};

#endif // __COMMANDLINE_COMMANDS_COMMAND_MANAGER_HPP__
