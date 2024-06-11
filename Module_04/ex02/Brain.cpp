#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& original) {
    for (int i = 0; i < 100; i++) {
        ideas[i] = original.getIdeas()[i];
    }
}

Brain& Brain::operator=(const Brain& original) {
    if (this != &original) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = original.getIdeas()[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

const std::string(&Brain::getIdeas() const)[100] {
    return this->ideas;
}
