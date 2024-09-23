
#include "commandException.hpp"

const char*
commandException::
what() const noexcept
{
    return "";
}

commandInvalidArgumentCount::
commandInvalidArgumentCount(std::size_t argCount)
    : m_argCount(argCount)
{}

const char* 
commandInvalidArgumentCount::
what() const noexcept
{
    return "Invalid Argument Count";
}
