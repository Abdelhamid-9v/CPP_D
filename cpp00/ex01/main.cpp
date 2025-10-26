#include "phonebook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    PhoneBook phoneBook;
    std::string cmd;
    
    std::cout << "Welcome to your awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (1)
    {
        std::cout << "Enter a cmd: ";

        if (!std::getline(std::cin, cmd))
        {
            std::cout << "\n";
            exit(1);
        }    
        
        if (cmd == "ADD") {
            phoneBook.addContact();
        }
        else if (cmd == "SEARCH") {
            phoneBook.searchContacts();
        }
        else if (cmd == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (!cmd.empty()) {
            std::cout << "Invalid command. Available commands: ADD, SEARCH, EXIT" << std::endl;
        }
    }
    
    return 0;
}