#include "commandException.hpp"
#include "commandManager.hpp" 

#include <vector>
#include <cassert>
#include <iostream>

class commandValidator
{

};

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
