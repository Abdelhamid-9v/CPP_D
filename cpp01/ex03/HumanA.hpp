#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon& weapon;  // Reference because HumanA always has a weapon

public:
    HumanA(const std::string& humanName, Weapon& humanWeapon);
    void attack() const;
};

#endif