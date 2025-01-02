#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>
#include <ctime>

class RobotomyRequestForm : public AForm {
    private:
        const std::string _target;
    
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &original);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &original);
        ~RobotomyRequestForm();

        std::string getTarget() const;

        void execute(Bureaucrat const & executor) const;
        AForm *clone() const;
        AForm *clone(std::string target) const;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &r);

#endif