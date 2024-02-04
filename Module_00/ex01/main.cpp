#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << YELLOW << "--Available commands: ADD, SEARCH, EXIT--" << RESET << std::endl;
    while (1) {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT") {
            std::cout << RED << "Exiting..." << RESET << std::endl;
            return (0);
        } else {
            std::cout << RED << "Invalid command" << RESET << std::endl;
        }
    }
    return (0);
}