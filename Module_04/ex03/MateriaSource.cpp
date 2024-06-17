#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& original) {
    for (int i = 0; i < 4; i++) {
        if (original.inventory[i] != NULL) {
            inventory[i] = original.inventory[i]->clone();
        } else
            inventory[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& original) {
    if (this != &original){
        for (int i = 0; i < 4; i++) {
            if (inventory[i] != NULL)
                delete inventory[i];
            if (original.inventory[i] != NULL) {
                inventory[i] = original.inventory[i]->clone();
            } else
                inventory[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL)
            delete inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia) {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = materia;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL && inventory[i]->getType() == type) {
            return inventory[i]->clone();
        }
    }
    return 0;
}