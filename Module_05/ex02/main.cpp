#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    std::cout << PURPLE << "---ShrubberyCreationForm---" << RESET << std::endl;
    ShrubberyCreationForm shrubbery("home");
    std::cout << shrubbery << std::endl;

    Bureaucrat juan("Juan", 111);
    std::cout << juan << std::endl;
    juan.signForm(shrubbery);
    std::cout << shrubbery << std::endl;
    juan.executeForm(shrubbery);

    std::cout << PURPLE << "\n---RobotomyRequestForm---" << RESET << std::endl;
    RobotomyRequestForm robotomy("Bob");
    std::cout << robotomy << std::endl;

    Bureaucrat alberto("Alberto", 31);
    std::cout << alberto << std::endl;
    alberto.signForm(robotomy);
    std::cout << robotomy << std::endl;
    alberto.executeForm(robotomy);

    std::cout << PURPLE << "\n---PresidentialPardonForm---" << RESET << std::endl;
    PresidentialPardonForm presidential("Alice");
    std::cout << presidential << std::endl;

    Bureaucrat elena("Elena", 5);
    std::cout << elena << std::endl;
    elena.signForm(presidential);
    std::cout << presidential << std::endl;
    elena.executeForm(presidential);

    return 0;
}