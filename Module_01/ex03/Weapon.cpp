#include "Weapon.hpp"

Weapon::Weapon( std::string type)
{
    this->_type = type;
}

Weapon::~Weapon( void ) {}

const std::string& Weapon::getType( void ) const
{
    return (_type);
}

void Weapon::setType( std::string type)
{
    this->_type = type;
}