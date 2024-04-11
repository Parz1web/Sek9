#include "FileHandler.h"
#include <filesystem>


int main() {

    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    FileHandler handler(filename);

    int choice;
    do {
        std::cout << "Choose an action:" << std::endl;
        std::cout << "1. Read text file" << std::endl;
        std::cout << "2. Read bytes file" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cin >> choice;

        switch (choice) {
        case 1:
        {
            std::string textContent = handler.readTextFile();
            std::cout << "Text content: " << textContent << std::endl;
            break;
        }
        case 2:
        {
            std::vector<char> bytesContent = handler.readBytesFile();
            std::cout << "Bytes content: ";
            for (char c : bytesContent) {
                std::cout << c << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 0:
            std::cout << "Exiting program..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
