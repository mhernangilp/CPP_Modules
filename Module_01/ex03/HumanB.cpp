#include "HumanB.hpp"

HumanB::HumanB ( std::string name )
{
    this->_weapon = NULL;
    this->_name = name;
}

HumanB::~HumanB( void ) {}

void HumanB::setWeapon( Weapon& weapon )
{
    this->_weapon = &weapon;
}

void HumanB::attack( void )
{
    if (_weapon == NULL)
        std::cout << "I can't attack because I am unarmed !" << std::endl;
    else
        std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}