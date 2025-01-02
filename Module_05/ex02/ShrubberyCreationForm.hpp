#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        const std::string _target;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &original);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &original);
        ~ShrubberyCreationForm();

        std::string getTarget() const;

        void execute(Bureaucrat const & executor) const;

        class FileOpenException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &s);

#endif