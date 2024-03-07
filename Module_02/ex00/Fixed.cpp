#include "Fixed.hpp"

const int Fixed::_fract = 8;

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& original)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(original.getRawBits());
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int    Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void    Fixed::setRawBits(int const raw)
{
    _value = raw;
}