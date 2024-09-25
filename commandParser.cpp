#include "commandParser.hpp"

commandParser::commandParser(char** argv)
    : m_commandLineArgs(argv)
{}

void 
commandParser::parse(int argc)
{
    setCommandName(m_commandLineArgs[0]);
    setArg1(m_commandLineArgs[1]);
    if (argc == 3) {
        setArg2(m_commandLineArgs[2]);
    }
}

std::string
commandParser::getCommandName() const
{
    return m_commandName;
}

char
commandParser::getArg1() const
{
    return m_commandArgs.arg1;
}

std::filesystem::path
commandParser::getArg2() const
{
    return m_commandArgs.arg2;
}

void commandParser::setCommandName(const std::string& cn)
{
    m_commandName = std::filesystem::path(cn).filename().string();
}

void
commandParser::setArg1(const std::string& a1)
{
    m_commandArgs.arg1 = a1[0];
    //if (startsWith(a1, std::string("-"))) {
    //    // m_commandArgs.arg1 = getCommandOption(a1);
    //    m_commandArgs.isDefaultOption = true;
    //} else {
    //    m_commandArgs.arg1 = std::filesystem::path(a1);
    //    m_commandArgs.isDefaultOption = false;
    //}
}

// TODO:/ this is file name case, but you got to know that arg1 was not the file name case
void 
commandParser::setArg2(const std::string& a2)
{
    //if (m_commandArgs.isDefaultOption) {
    //     throw -1;
    //    // TODO implemat this one
    //    // throw InvalidCommandOrSomting();
    //}
    m_commandArgs.arg2 = std::filesystem::path(a2);
}

bool 
commandParser::startsWith(std::string_view str, std::string_view prefix)
{
    return str.substr(0, prefix.size()) == prefix;
}

//commandParser::commandArgs::commandOption
//commandParser::getCommandOption(std::string_view a1)
//{
//    if (a1.size() > 2) {
//        // TODO this is exception case you need an handling for this
//        throw -1;
//    }
//    // TODO do I need to have combined options?
//    if (a1[1] == 'c') {
//        return commandArgs::commandOption::c;
//    } else if (a1[1] == 'l') {
//        return commandArgs::commandOption::l;
//    } else if (a1[1] == 'w') {
//        return commandArgs::commandOption::w;
//    } else if (a1[1] == 'm') {
//        return commandArgs::commandOption::m;
//    }
//    return commandArgs::commandOption::invalid;
//}
