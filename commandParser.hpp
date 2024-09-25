#ifndef __COMMANDLINE_COMMANDS_COMMAND_PARSER_HPP__
#define __COMMANDLINE_COMMANDS_COMMAND_PARSER_HPP__

#include <variant>
#include <filesystem>
#include <string_view>

class commandParser
{
public:
    commandParser(char** argv);

    void parse(int argc);
    std::string getCommandName() const;
    char getArg1() const;
    std::filesystem::path getArg2() const;

private:
    // This function returns out.exe for windows and probably will return out for Linux 
    // TODO:/ make it more flexible for all OSs
    void setCommandName(const std::string& cn);
    void setArg1(const std::string& a1);
    // TODO:/ this is file name case, but you got to know that arg1 was not the file name case
    void setArg2(const std::string& a2);

private:
    bool startsWith(std::string_view str, std::string_view prefix);
    // commandParser::commandArgs::commandOption getCommandOption(std::string_view a1);

private:
    struct commandArgs {
        bool isDefaultOption;
        char arg1;
        std::filesystem::path arg2;
    };

private:
    char** m_commandLineArgs;
    std::string m_commandName;
    commandArgs m_commandArgs;
};

#endif // __COMMANDLINE_COMMANDS_COMMAND_PARSER_HPP__
