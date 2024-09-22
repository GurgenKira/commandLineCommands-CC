#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <exception>
#include <filesystem>
#include <variant>

class commandException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "";
    }
};

// TODO can I use argCont for more general exception type
// BTW you can add more information about -help option as well
class commandInvalidArgumentCount : public commandException
{
public:
    commandInvalidArgumentCount(std::size_t argCount)
        : m_argCount(argCount)
    {}

    const char* what() const noexcept override
    {
        return "Invalid Argument Count";
    }

private:
    std::size_t m_argCount;
};

class command
{
public:
    virtual void execute() const = 0;
};

class wc : public command 
{
public:
    void execute() const override
    {
        std::cout << "wc command was executed" << std::endl;
    }
};

class commandParser
{
public:
    commandParser(char** argv)
        : m_commandLineArgs(argv)
    {}

    void parse(int argc)
    {
        setCommandName(m_commandLineArgs[0]);
        setArg1(m_commandLineArgs[1]);
        if (argc == 3) {
            setArg2(m_commandLineArgs[2]);
        }
    }

    std::string getCommandName() const
    {
        return m_commandName;
    }

        //std::variant<std::filesystem::path, commandOption> arg1;
        // arg2;
    std::variant<std::filesystem::path, commandArgs::commandOption> getArg1() const
    {
        return m_commandArgs.arg1;
    }

    std::filesystem::path getArg2() const
    {
        return m_commandArgs.arg2;
    }

private:
    // This function returns out.exe for windows and probably will return out for Linux 
    // TODO:/ make it more flexible for all OSs
    void setCommandName(const std::string& cn)
    {
        m_commandName = std::filesystem::path(cn).filename().string();
    }

    void setArg1(const std::string& a1)
    {
        if (startsWith(a1, std::string("-"))) {
            m_commandArgs.arg1 = getCommandOption(a1);
            m_commandArgs.isDefaultOption = true;
        } else {
            m_commandArgs.arg1 = std::filesystem::path(a1);
            m_commandArgs.isDefaultOption = false;
        }
    }

    // TODO:/ this is file name case, but you got to know that arg1 was not the file name case
    void setArg2(const std::string& a2)
    {
        if (m_commandArgs.isDefaultOption) {
             throw -1;
            // TODO implemat this one
            // throw InvalidCommandOrSomting();
        }
        m_commandArgs.arg2 = std::filesystem::path(a2);
    }

private:
    bool startsWith(std::string_view str, std::string_view prefix)
    {
        return str.substr(0, prefix.size()) == prefix;
    }
    
    commandParser::commandArgs::commandOption getCommandOption(std::string_view a1)
    {
        if (a1.size() > 2) {
            // TODO this is exception case you need an handling for this
            throw -1;
        }
        // TODO do I need to have combined options?
        if (a1[1] == 'c') {
            return commandArgs::commandOption::c;
        } else if (a1[1] == 'l') {
            return commandArgs::commandOption::l;
        } else if (a1[1] == 'w') {
            return commandArgs::commandOption::w;
        } else if (a1[1] == 'm') {
            return commandArgs::commandOption::m;
        }
        return commandArgs::commandOption::invalid;
    }

private:
    struct commandArgs {
        enum class commandOption {
            c, l, w, m, invalid
        };
        bool isDefaultOption;
        std::variant<std::filesystem::path, commandOption> arg1;
        std::filesystem::path arg2;
    };

private:
    char** m_commandLineArgs;
    std::string m_commandName;
    commandArgs m_commandArgs;
};

class commandManager
{
public:
    commandManager(int argc, char** argv)
    {
        if (argc < 2 || argc > 3) {
            throw commandInvalidArgumentCount(argc);
        }
        commandParser parser(argv);
        parser.parse(argc);
    }

    void run()
    {
        assert(m_currentCommand);
        m_currentCommand->execute();
    }

private:
    std::unique_ptr<command> m_currentCommand;
};

class commandValidator
{

};

void parseCommandLineArgs(int argc, char** argv)
{
}

void run(int argc, char** argv)
{
    parseCommandLineArgs(argc, argv);
}

int main(int argc, char** argv)
{
    try {
        commandManager com(argc, argv);
        // com.run();
    } catch(const commandException& ce) {
        std::cout << ce.what() << std::endl;
    } catch (const std::exception& se) {
        std::cout << se.what() << std::endl;
    } catch (...) {
        assert(false && "Application was interptd by unknow exception");
    }

    return 0;
}