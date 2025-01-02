#include "Bureaucrat.hpp"

int main(void) {
    std::cout << PURPLE << "---Alberto---" << RESET << std::endl;
    try {
        Bureaucrat alberto("Alberto", 0);
    } catch (std::exception &e) {
        std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
    }

    std::cout << PURPLE << "\n---Juan---" << RESET << std::endl;
    Bureaucrat juan("Juan", 2);
    std::cout << juan << std::endl;
    juan.incrementGrade();
    std::cout << juan << std::endl;
    try {
        juan.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
    }

    std::cout << PURPLE << "\n---Elena---" << RESET << std::endl;
    Bureaucrat elena("Elena", 149);
    std::cout << elena << std::endl;
    elena.decrementGrade();
    std::cout << elena << std::endl;
    try {
        elena.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
    }

    return 0;
}