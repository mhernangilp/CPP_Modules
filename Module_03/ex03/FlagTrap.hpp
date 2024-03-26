#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : virtual public ClapTrap {
    public:
        FlagTrap(void);
        FlagTrap(std::string name);
        ~FlagTrap(void);

        void    attack(const std::string& target);
        void    highFivesGuys(void);

        static const int defaultHitPoints = 100;
		static const int defaultEnergyPoints = 100;
		static const int defaultAttackDamage = 30;
};

#endif