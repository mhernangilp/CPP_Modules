#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) : AForm("ShrubberyCreationForm", 145, 137), _target(original._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original) {
    if (this != &original) {
        AForm::operator=(original);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const { return _target; }

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw ShrubberyCreationForm::FileOpenException();
    file << "                                                         .\n"
         << "                                              .         ;\n"
         << "                 .              .              ;%     ;;\n"
         << "                   ,           ,                :;%  %;\n"
         << "                    :         ;                   :;%;'     .,\n"
         << "           ,.        %;     %;            ;        %;'    ,;\n"
         << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
         << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
         << "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
         << "                `%;.     ;%;     %;'         `;%%;.%;'\n"
         << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
         << "                    `:%;.  :;bd%;          %;@%;'\n"
         << "                      `@%:.  :;%.         ;@@%;'\n"
         << "                        `@%.  `;@%.      ;@@%;\n"
         << "                          `@%%. `@%%    ;@@%;\n"
         << "                            ;@%. :@%%  %@@%;\n"
         << "                              %@bd%%%bd%%:;\n"
         << "                                #@%%%%%:;;\n"
         << "                                %@@%%%::;\n"
         << "                                %@@@%(o);  . '\n"
         << "                                %@@@o%;:(.,'\n"
         << "                            `.. %@@@o%::;\n"
         << "                               `)@@@o%::;\n"
         << "                                %@@(o)::;\n"
         << "                               .%@@@@%::;\n"
         << "                               ;%@@@@%::;.\n"
         << "                              ;%@@@@%%:;;;.\n"
         << "                          ...;%@@@@@%%:;;;;,..\n";
    file.close();
}

AForm *ShrubberyCreationForm::clone() const {
    return new ShrubberyCreationForm(*this);
}

AForm *ShrubberyCreationForm::clone(std::string target) const {
    return new ShrubberyCreationForm(target);
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "couldn't create file";
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &s) {
    out << s.getName() << ", form ";
    if (s.getSigned())
        out << "IS ";
    else
        out << "IS NOT ";
    out << "signed, with sign grade " << s.getSignGrade() << " and execute grade " << s.getExecGrade() << " and target " << s.getTarget();
    return out;
}