#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){};

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "[" << _name << "] (ScavTrap) I am alive :)" << std::endl;
    _hitPoints = defaultHitPoints;
    _energyPoints = defaultEnergyPoints;
    _attackDamage = defaultAttackDamage;
}

ScavTrap::~ScavTrap(void) {std::cout << "[" << _name << "] (ScavTrap) I am dead :(" << std::endl;}

void    ScavTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
        std::cout << YELLOW << "ScavTrap " << _name << " wants to attack " << target << " but it has 0 energy points !" << RESET << std::endl;
    else {
        _energyPoints--;
        std::cout << YELLOW << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage ! - [" << _hitPoints <<
            " HP, " << _energyPoints << " EP]" << RESET << std::endl;
    }
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is in Gate keeper mode !" << std::endl;
}
