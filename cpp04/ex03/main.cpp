#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>


int main()
{
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");
    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob);
    // me->use(1, *bob);
    // delete bob;
    // delete me;
    // delete src;


    // simple test without MateriaSource

    
    // AMateria *ice = new Ice();
    // AMateria *cure = new Cure();
    // ICharacter *hero = new Character("Hero");
    // hero->equip(ice);
    // hero->equip(cure);
    // hero->use(0, *hero);
    // hero->use(1, *hero);
    // delete hero;

    // std::cout << "=== TEST: Your unequip() function ===" << std::endl;
    
    // Character hero("Hero");
    // Character target("Target");
    // AMateria* ice = new Ice();
    // AMateria* cure = new Cure();
    // hero.equip(ice);
    // hero.equip(cure);
    
    // std::cout << "Before unequip:" << std::endl;
    // hero.use(0, target);  
    // hero.use(1, target); 
    
    // AMateria* savedIceAddress = ice;
    // std::cout << "Saved Ice address: " << savedIceAddress << std::endl;

    // hero.unequip(0);

    // std::cout << "After unequip:" << std::endl;
    // hero.use(0, target);
    // hero.use(1, target); 
    
    // delete savedIceAddress;
    
    return 0;
}
