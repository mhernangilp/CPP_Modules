#include "Intern.hpp"

Intern::Intern() {
    _formTemplates[0] = new ShrubberyCreationForm();
    _formTemplates[1] = new RobotomyRequestForm();
    _formTemplates[2] = new PresidentialPardonForm();
}
Intern::Intern(const Intern &original) {
    for (int i = 0; i < 3; i++)
        _formTemplates[i] = original._formTemplates[i]->clone();
}
Intern& Intern::operator=(const Intern &original) {
    if (this != &original) {
        for (int i = 0; i < 3; i++) {
            delete _formTemplates[i];
            _formTemplates[i] = original._formTemplates[i]->clone();
        }
    }
    return *this;
}

Intern::~Intern() {
    for (int i = 0; i < 3; i++)
        delete _formTemplates[i];
}

const AForm * const *Intern::getFormTemplates() const { return _formTemplates; }

AForm *Intern::makeForm(std::string formName, std::string target) {
    for (int i = 0; i < 3; i++)
        if (_formTemplates[i]->getName() == formName)
            return _formTemplates[i]->clone(target);
    throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}