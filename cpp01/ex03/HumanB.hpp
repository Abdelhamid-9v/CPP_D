#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // Pointer because HumanB may not have a weapon

public:
    HumanB(const std::string& humanName);
    void setWeapon(Weapon& humanWeapon);
    void attack() const;
};

#endif