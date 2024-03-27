#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(){};

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "[" << _name << "] (FragTrap) I am alive :)" << std::endl;
    _hitPoints = defaultHitPoints;
    _energyPoints = defaultEnergyPoints;
    _attackDamage = defaultAttackDamage;
}

FragTrap::~FragTrap(void) {std::cout << "[" << _name << "] (FragTrap) I am dead :(" << std::endl;}

void    FragTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
        std::cout << YELLOW << "FragTrap " << _name << " wants to attack " << target << " but it has 0 energy points !" << RESET << std::endl;
    else {
        _energyPoints--;
        std::cout << YELLOW << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage ! - [" << _hitPoints <<
            " HP, " << _energyPoints << " EP]" << RESET << std::endl;
    }
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " says high five !" << std::endl;
}
