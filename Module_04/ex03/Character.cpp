#include "Character.hpp"

Character::Character(const std::string name) : name(name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character& original) : name(original.getName()) {
    for (int i = 0; i < 4; i++) {
        if (original.inventory[i] != NULL) {
            inventory[i] = original.inventory[i]->clone();
        } else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& original) {
    if (this != &original){
        name = original.getName();

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

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL)
            delete inventory[i];
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx) {
    if (inventory[idx] != NULL) {
        delete inventory[idx];
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (inventory[idx] != NULL) {
        inventory[idx]->use(target);
    } else {
        std::cout << "- Not a valid materia -" << std::endl;
    }
}
