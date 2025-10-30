#include"Zombie.hpp"


Zombie::Zombie() : name("no_name") {}

Zombie::Zombie(std::string Zname) : name(Zname) {}

Zombie::~Zombie() {
    std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

