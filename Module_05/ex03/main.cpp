#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
    std::cout << PURPLE << "---Success---" << RESET << std::endl;
    Intern intern;
    AForm *form;

    form = intern.makeForm("PresidentialPardonForm", "Bob");
    std::cout << *form << std::endl;

    Bureaucrat juan("Juan", 4);
    std::cout << juan << std::endl;

    juan.signForm(*form);
    juan.executeForm(*form);

    delete form;

    std::cout << PURPLE << "\n---Failure---" << RESET << std::endl;
    Intern newIntern;
    AForm *newForm;

    try {
        newForm = intern.makeForm("somethingwrong", "Alice");
        std::cout << newForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
    }

    return 0;
}