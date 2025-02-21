#include <iostream>
#include "Array.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define PURPLE  "\033[35m"
#define ORANGE  "\033[38;5;214m"

int main() {
    try {
        std::cout << ORANGE << "Without parameters" << RESET << std::endl;   
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        std::cout << ORANGE << "\nWith custom size" << RESET << std::endl;
        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); i++) {
            numbers[i] = i;
        }
        std::cout << "Numbers array: ";
        for (unsigned int i = 0; i < numbers.size(); i++) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;

        std::cout << ORANGE << "\nCopy" << RESET << std::endl;
        Array<int> copy(numbers);
        copy[0] = 999;
        std::cout << "Original first element: " << numbers[0] << std::endl;
        std::cout << "Copied first element: " << copy[0] << std::endl;

        std::cout << ORANGE << "\nOut of range" << RESET << std::endl;
        std::cout << numbers[10] << std::endl; // Lanza excepción

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
