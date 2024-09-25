#include "commands.hpp"

#include <fstream>
#include <iostream>

void
wc::execute() const
{
    std::vector<char> fileContent;

    std::ifstream file(m_file, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open the file: " << m_file<< std::endl;
    }

    std::streamsize fileSize = file.tellg();
    fileContent.resize(fileSize);

    file.seekg(0, std::ios::beg);
    if (file.read(fileContent.data(), fileSize)) {
        std::cout << fileSize << " " << m_file.string() << std::endl;
    } else {
        std::cerr << "Error: Only " << file.gcount() << " could be read from the file: " << m_file << std::endl;
    }


    file.close();

}
