#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name) {
    copyInventory(other);
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        clearInventory();
        copyInventory(other);
    }
    return *this;
}

Character::~Character() {
    clearInventory();
}

void Character::clearInventory() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL) {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
}

void Character::copyInventory(const Character& other) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
        if (other.inventory[i] != NULL) {
            inventory[i] = other.inventory[i]->clone();
        }
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4) return;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
        return;
    inventory[idx]->use(target);
}