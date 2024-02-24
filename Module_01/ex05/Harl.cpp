#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::debug(void)
{
    std::cout << BLUE << "[DEBUG]" << RESET << " This is a debug message" << std::endl;
}

void    Harl::info(void)
{
    std::cout << GREEN << "[INFO]" << RESET << " This is a info message" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << ORANGE << "[WARNING]" << RESET << " This is a warning message" << std::endl;
}

void    Harl::error(void)
{
    std::cout << RED << "[ERROR]" << RESET << " This is a error message" << std::endl;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*func_arr[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i += 1)
		if (level == levels[i])
			(this->*func_arr[i])();
}