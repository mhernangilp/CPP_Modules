#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon): _weapon(weapon)
{
    this->_name = name;
}

HumanA::~HumanA() {}

void HumanA::attack( void )
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}