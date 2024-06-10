#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& original) : Animal(original){
    brain = new Brain(original.getBrain());
}

Cat& Cat::operator=(const Cat& original) {
    if (this != &original){
        Animal::operator=(original);
        delete this->brain;
        this->brain = new Brain(original.getBrain());
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

const Brain& Cat::getBrain() const {
    return *brain;
}

void Cat::makeSound() const {
    std::cout << "Miau miau miau ..." << std::endl;
}