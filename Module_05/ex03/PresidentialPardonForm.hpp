#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        const std::string _target;
    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &original);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &original);
        ~PresidentialPardonForm();

        std::string getTarget() const;

        void execute(Bureaucrat const & executor) const;
        AForm *clone() const;
        AForm *clone(std::string target) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &s);

#endif