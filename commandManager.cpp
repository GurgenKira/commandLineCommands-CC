#include "commandException.hpp"
#include "commandManager.hpp"
#include "commandParser.hpp"

#include <cassert>

commandManager::commandManager(int argc, char** argv)
{
    if (argc < 2 || argc > 3) {
        throw commandInvalidArgumentCount(argc);
    }
    commandParser parser(argv);
    parser.parse(argc);
}

void
commandManager::run()
{
    assert(m_currentCommand);
    m_currentCommand->execute();
}
