#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor called" << std::endl;
    type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& original) : type(original.getType()) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original) {
    if (this != &original) {
        this -> type = original.getType();
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this -> type;
}

void WrongAnimal::makeSound() const {
    std::cout << "Some generic WrongAnimal sound ..." << std::endl;
}