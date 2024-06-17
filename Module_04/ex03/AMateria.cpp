#include "AMateria.hpp"

AMateria::AMateria() : type("undefined") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& original) : type(original.getType()) {}

AMateria& AMateria::operator=(const AMateria& original) {
    if (this != &original) {
        this->type = original.getType();
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* some generic material does something to " << target.getName() << " *" << std::endl;
}
