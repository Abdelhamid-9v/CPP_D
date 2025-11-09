#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;

    Animal* animals[4];
    std::cout << "\n------------------------\n" << std::endl;
    std::cout << "Creating an array of Animals:" << std::endl;
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    std::cout << "\n------------------------\n" << std::endl;
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();
    std::cout << "\n------------------------\n" << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];


         std::cout << "\n=== DEEP COPY TESTS ===" << std::endl;
    
    // Test 1: Dog Deep Copy
    std::cout << "\n--- Testing Dog Deep Copy ---" << std::endl;
    Dog original_dog;
    original_dog.setIdea(0, "fikra_1");
    original_dog.setIdea(1, "fikra_2");
    
    Dog copied_dog(original_dog);
    copied_dog.setIdea(1, "copy_fikra_2");
    
    std::cout << "Original Dog idea 0: " << original_dog.getIdea(0) << std::endl;
    std::cout << "Original Dog idea 1: " << original_dog.getIdea(1) << std::endl;
    std::cout << "Copied Dog idea 0: " << copied_dog.getIdea(0) << std::endl;
    std::cout << "Copied Dog idea 1: " << copied_dog.getIdea(1) << std::endl;
    
    std::cout << "Original brain address: " << original_dog.getBrainAddress() << std::endl;
    std::cout << "Copied brain address: " << copied_dog.getBrainAddress() << std::endl;
    
    // Test 2: Cat Deep Copy
    std::cout << "\n\n--- Testing Cat Deep Copy ---\n" << std::endl;
    Cat original_cat;
    original_cat.setIdea(0, "fikra_A");
    
    Cat assigned_cat;
    assigned_cat = original_cat;
    assigned_cat.setIdea(0, "copy_fikra_A");
    
    std::cout << "Original Cat idea 0: " << original_cat.getIdea(0) << std::endl;
    std::cout << "Assigned Cat idea 0: " << assigned_cat.getIdea(0) << std::endl;
    
    std::cout << "Original brain address: " << original_cat.getBrainAddress() << std::endl;
    std::cout << "Assigned brain address: " << assigned_cat.getBrainAddress() << std::endl;
    return 0;
}