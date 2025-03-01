#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define PURPLE  "\033[35m"

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(int grade);
        Bureaucrat(const Bureaucrat &original);
        Bureaucrat& operator=(const Bureaucrat &original);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif