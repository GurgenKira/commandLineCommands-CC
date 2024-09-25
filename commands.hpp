#ifndef __COMMANDLINE_COMMANDS_COMMANDS_HPP__
#define __COMMANDLINE_COMMANDS_COMMANDS_HPP__

#include <filesystem>

class command
{
public:
    virtual void execute() const = 0;
};

class wc : public command 
{
public:
    wc(const char option, const std::filesystem::path& file)
        : m_option(option)
        , m_file(file) 
    {

    }

public:
    void execute() const override;

private:
    char m_option;
    std::filesystem::path m_file;
};

#endif // __COMMANDLINE_COMMANDS_COMMANDS_HPP__
