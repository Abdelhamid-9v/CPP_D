#include "Zombie.hpp"

int main(void)
{
    Zombie a("z1");
    Zombie *b;

    a.announce();

    b = newZombie("z2");
    b->announce();
    delete b;

    randomChump("z3");
    return 0;
}