#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Animal animal;
    // Animal* meta = new Animal(); // compilation error as Animal is now abstract
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // Outputs cat sound
    j->makeSound(); // Outputs dog sound
    
    delete j;
    delete i;

    // ✅ Array of Animals still works:
    Animal* animals[4];
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();
    
    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
        delete animals[i];
    }

    return 0;
}