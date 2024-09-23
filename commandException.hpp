#ifndef __COMMANDLINE_COMMANDS_COMMAND_EXCEPTION_HPP__
#define __COMMANDLINE_COMMANDS_COMMAND_EXCEPTION_HPP__

#include <exception>

class commandException : public std::exception
{
public:
    const char* what() const noexcept override;
};

// TODO can I use argCont for more general exception type
// BTW you can add more information about -help option as well
class commandInvalidArgumentCount : public commandException
{
public:
    commandInvalidArgumentCount(std::size_t argCount);

    const char* what() const noexcept override;

private:
    std::size_t m_argCount;
};


#endif // __COMMANDLINE_COMMANDS_COMMAND_EXCEPTION_HPP__
