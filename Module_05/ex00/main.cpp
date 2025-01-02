#include "Bureaucrat.hpp"

int main(void) {
    std::cout << PURPLE << "---Alberto---" << RESET << std::endl;
    try {
        Bureaucrat Alberto("Alberto", 0);
    } catch (std::exception &e) {
        std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
    }

    std::cout << PURPLE << "\n---Juan---" << RESET << std::endl;
    Bureaucrat Juan("Juan", 2);
    std::cout << Juan << std::endl;
    Juan.incrementGrade();
    std::cout << Juan << std::endl;
    try {
        Juan.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
    }

    std::cout << PURPLE << "\n---Elena---" << RESET << std::endl;
    Bureaucrat Elena("Elena", 149);
    std::cout << Elena << std::endl;
    Elena.decrementGrade();
    std::cout << Elena << std::endl;
    try {
        Elena.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
    }

    return 0;
}