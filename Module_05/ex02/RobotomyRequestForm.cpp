#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) : AForm("RobotomyRequestForm", 72, 45), _target(original._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &original) {
    if (this != &original) {
        AForm::operator=(original);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const { return _target; }

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << YELLOW << "Some drilling noises ..." << std::endl;
    std::srand(std::time(0));
    if (rand() % 2)
        std::cout << _target << " has been robotomized succesfully" << RESET << std::endl;
    else
        std::cout << "The robotomy failed for " << _target << " :(" << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &s) {
    out << s.getName() << ", form ";
    if (s.getSigned())
        out << "IS ";
    else
        out << "IS NOT ";
    out << "signed, with sign grade " << s.getSignGrade() << " and execute grade " << s.getExecGrade() << " and target " << s.getTarget();
    return out;
}