#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FlagTrap(), ScavTrap() {};

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FlagTrap(name), ScavTrap(name)
{
    _name = name;
    _hitPoints = FlagTrap::defaultHitPoints;
    _energyPoints = ScavTrap::defaultEnergyPoints;
    _attackDamage = FlagTrap::defaultAttackDamage;
    std::cout << "[" << _name << "] (DiamondTrap) I am alive :)" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original): ClapTrap(original), FlagTrap(original), ScavTrap(original)
{
    _name = original._name;
    ClapTrap::_name = (_name + "_clap_name");
    _hitPoints = original._hitPoints;
    _energyPoints = original._energyPoints;
    _attackDamage = original._attackDamage;
    std::cout << "[" << _name << "]" << " (DiamondTrap) I am alive by copy :)" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
    if (this != &original) {
        _name = original._name;
        ClapTrap::_name = (_name + "_clap_name");
        _hitPoints = original._hitPoints;
        _energyPoints = original._energyPoints;
        _attackDamage = original._attackDamage;
    }
    std::cout << "[" << _name << "]" << " (DiamondTrap) I am alive by Assignment Operator :)" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap(void) {std::cout << "[" << _name << "] (DiamondTrap) I am dead :(" << std::endl;}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << _name << "\nClapTrap name: " << ClapTrap::_name << std::endl;
}