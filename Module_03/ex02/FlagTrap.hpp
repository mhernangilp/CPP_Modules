#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap {
    public:
        FlagTrap(std::string name);
        ~FlagTrap(void);

        void    attack(const std::string& target);
        void    highFivesGuys(void);
};

#endif