#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class FileHandler {
private:
    std::string filename;

public:
    FileHandler(std::string filename);

    std::string readTextFile();
    std::string writeTextFile(std::string content);
    std::vector<char> readBytesFile();
    std::string writeBytesFile(std::vector<char> content);
};