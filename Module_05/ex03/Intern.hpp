#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    private:
        AForm *_formTemplates[3];

    public:
        Intern();
        Intern(const Intern &original);
        Intern& operator=(const Intern &original);
        ~Intern();

        const AForm * const *getFormTemplates() const;

        AForm *makeForm(std::string formName, std::string target);

        class FormNotFoundException : public std::exception {
            public:
                const char *what() const throw();
        };
};

#endif