#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void) : ClapTrap(){};

FlagTrap::FlagTrap(std::string name): ClapTrap(name)
{
    std::cout << "[" << _name << "] (FlagTrap) I am alive :)" << std::endl;
    _hitPoints = defaultHitPoints;
    _energyPoints = defaultEnergyPoints;
    _attackDamage = defaultAttackDamage;
}

FlagTrap::~FlagTrap(void) {std::cout << "[" << _name << "] (FlagTrap) I am dead :(" << std::endl;}

void    FlagTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
        std::cout << YELLOW << "FlagTrap " << _name << " wants to attack " << target << " but it has 0 energy points !" << RESET << std::endl;
    else {
        _energyPoints--;
        std::cout << YELLOW << "FlagTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage ! - [" << _hitPoints <<
            " HP, " << _energyPoints << " EP]" << RESET << std::endl;
    }
}

void    FlagTrap::highFivesGuys(void)
{
    std::cout << "FlagTrap " << _name << " says high five !" << std::endl;
}
