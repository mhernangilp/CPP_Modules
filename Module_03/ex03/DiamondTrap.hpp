#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
    private:
        std::string _name;
    
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &original);
        DiamondTrap &operator=(const DiamondTrap &original);
        ~DiamondTrap(void);

        using ScavTrap::attack;
        void    whoAmI(void);
};

#endif