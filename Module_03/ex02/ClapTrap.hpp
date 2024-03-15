#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define PURPLE  "\033[35m"

#include <string>
#include <iostream>

class ClapTrap {
    protected:
        const std::string   _name;
        unsigned int        _hitPoints;
        unsigned int        _energyPoints;
        unsigned int        _attackDamage;

    public:
        ClapTrap (std::string name);
        ClapTrap (const ClapTrap& original);
        ClapTrap& operator=(const ClapTrap& original);
        ~ClapTrap();

        const std::string&  getName() const;
        unsigned int        getHitPoints() const;
        unsigned int        getEnergyPoints() const;
        unsigned int        getAttackDamage() const;

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif