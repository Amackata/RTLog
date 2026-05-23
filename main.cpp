/*************************************************************
* RTLog++ - Amackata's Codes version 0.0.1a
* Examples Launcher
*************************************************************/
#include <iostream>
#include <cstdlib>
#include <filesystem>

namespace
{
    void printMenu()
    {
        std::cout << "\n";
        std::cout << "  RTLog++ v0.0.1a — Examples\n";
        std::cout << "  ===========================\n";
        std::cout << "  1. SDL3 Window\n";
        std::cout << "  2. Terminal (coming soon)\n";
        std::cout << "  0. Exit\n";
        std::cout << "\n";
        std::cout << "  Select: ";
    }
}

int main()
{
    const std::filesystem::path binDir(RTLOG_BIN_DIR);

    int choice = -1;
    while (choice != 0)
    {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::system((binDir / "sdl3_demo").string().c_str());
            break;
        case 2:
            std::cout << "  [Coming soon]\n";
            break;
        case 0:
            std::cout << "  Bye.\n";
            break;
        default:
            std::cout << "  Invalid option.\n";
            break;
        }
    }
    return 0;
}