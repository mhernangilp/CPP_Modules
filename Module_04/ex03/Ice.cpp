#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const & type) : AMateria(type) {}

Ice::Ice(const Ice& original) : AMateria(original) {}

Ice& Ice::operator=(const Ice& original) {
    if (this != &original) {
        AMateria::operator=(original);
    }
    return *this;
}

Ice::~Ice() {}

Ice* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}