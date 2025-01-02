#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(75), _execGrade(75) {}

AForm::AForm(std::string name) : _name(name),  _signed(false), _signGrade(75), _execGrade(75) {}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name),  _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &original) : _name(original._name), _signed(original._signed), _signGrade(original._signGrade), _execGrade(original._execGrade) {}

AForm& AForm::operator=(const AForm &original) {
    if (this != &original) {
        _signed = original._signed;
    }
    return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const { return _name; }

bool AForm::getSigned() const { return _signed; }

int AForm::getSignGrade() const { return _signGrade; }

int AForm::getExecGrade() const { return _execGrade; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (_signed)
        std::cout << ORANGE << "Warning. Trying to sign a previously signed form" << RESET << std::endl;
    if (bureaucrat.getGrade() <= _signGrade)
        _signed = true;
    else
        throw GradeTooLowException();
}
 
const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << f.getName() << ", form ";
    if (f.getSigned())
        out << "IS ";
    else
        out << "IS NOT ";
    out << "signed, with sign grade " << f.getSignGrade() << " and execute grade " << f.getExecGrade();
    return out;
}