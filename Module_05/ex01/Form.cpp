#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(75), _execGrade(75) {}

Form::Form(std::string name) : _name(name),  _signed(false), _signGrade(75), _execGrade(75) {}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name),  _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &original) : _name(original._name), _signed(original._signed), _signGrade(original._signGrade), _execGrade(original._execGrade) {}

Form& Form::operator=(const Form &original) {
    if (this != &original) {
        _signed = original._signed;
    }
    return *this;
}

Form::~Form() {}

const std::string Form::getName() const { return _name; }

bool Form::getSigned() const { return _signed; }

int Form::getSignGrade() const { return _signGrade; }

int Form::getExecGrade() const { return _execGrade; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (_signed)
        std::cout << ORANGE << "Warning. Trying to sign a previously signed form" << RESET << std::endl;
    if (bureaucrat.getGrade() <= _signGrade)
        _signed = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
    out << f.getName() << ", form ";
    if (f.getSigned())
        out << "IS ";
    else
        out << "IS NOT ";
    out << "signed, with sign grade " << f.getSignGrade() << " and execute grade " << f.getExecGrade();
    return out;
}