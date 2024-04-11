// FileHandler.cpp
#include "FileHandler.h"

FileHandler::FileHandler(std::string filename) : filename(filename) {}

std::string FileHandler::readTextFile() {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    }
    else {
        return "Файл не найден";
    }
}

std::string FileHandler::writeTextFile(std::string content) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        return "Файл успешно записан";
    }
    else {
        return "Не удалось записать файл";
    }
}

std::vector<char> FileHandler::readBytesFile() {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        std::vector<char> content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    }
    else {
        return {};
    }
}

std::string FileHandler::writeBytesFile(std::vector<char> content) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        file.write(content.data(), content.size());
        file.close();
        return "Файл успешно записан";
    }
    else {
        return "Не удалось записать в файл";
    }
}
