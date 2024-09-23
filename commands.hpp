#ifndef __COMMANDLINE_COMMANDS_COMMANDS_HPP__
#define __COMMANDLINE_COMMANDS_COMMANDS_HPP__

class command
{
public:
    virtual void execute() const = 0;
};

class wc : public command 
{
public:
    void execute() const override;
};

#endif // __COMMANDLINE_COMMANDS_COMMANDS_HPP__
