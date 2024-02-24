#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::debug(void)
{
    void    (Harl::*f_info) (void) = &Harl::info;

    std::cout << BLUE << "[DEBUG]" << RESET << " This is a debug message" << std::endl;
    (this->*f_info)();
}

void    Harl::info(void)
{
    void    (Harl::*f_warning) (void) = &Harl::warning;

    std::cout << GREEN << "[INFO]" << RESET << " This is a info message" << std::endl;
    (this->*f_warning)();
}

void    Harl::warning(void)
{
    void    (Harl::*f_error) (void) = &Harl::error;

    std::cout << ORANGE << "[WARNING]" << RESET << " This is a warning message" << std::endl;
        (this->*f_error)();
}

void    Harl::error(void)
{
    std::cout << RED << "[ERROR]" << RESET << " This is a error message" << std::endl;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*f_debug) (void) = &Harl::debug;
    void    (Harl::*f_info) (void) = &Harl::info;
    void    (Harl::*f_warning) (void) = &Harl::warning;
    void    (Harl::*f_error) (void) = &Harl::error;

    if (level == "DEBUG")
        (this->*f_debug)();
    else if (level == "INFO")
        (this->*f_info)();
    else if (level == "WARNING")
        (this->*f_warning)();
    else if (level == "ERROR")
        (this->*f_error)();
    else
        std::cout << "Please select a valid parameter (DEBUG, INFO, WARNING, ERROR)" << std::endl;
}