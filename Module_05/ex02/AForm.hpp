#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;

    public:
        AForm();
        AForm(std::string name);
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &original);
        AForm& operator=(const AForm &original);
        virtual ~AForm();

        const std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif