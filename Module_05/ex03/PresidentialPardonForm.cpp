#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original) : AForm("PresidentialPardonForm", 25, 5), _target(original._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &original) {
    if (this != &original) {
        AForm::operator=(original);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const { return _target; }

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    
    std::cout << YELLOW << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

AForm *PresidentialPardonForm::clone() const {
    return new PresidentialPardonForm(*this);
}

AForm *PresidentialPardonForm::clone(std::string target) const {
    return new PresidentialPardonForm(target);
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &s) {
    out << s.getName() << ", form ";
    if (s.getSigned())
        out << "IS ";
    else
        out << "IS NOT ";
    out << "signed, with sign grade " << s.getSignGrade() << " and execute grade " << s.getExecGrade() << " and target " << s.getTarget();
    return out;
}