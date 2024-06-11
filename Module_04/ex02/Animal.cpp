#include "Animal.hpp"

Animal::Animal() : type("Animal"){
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& original) : type(original.getType()) {}

Animal& Animal::operator=(const Animal& original) {
    if (this != &original) {
        this -> type = original.getType();
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return this -> type;
}
