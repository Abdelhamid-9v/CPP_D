#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name )
{
    if(N < 1)
    {
        std::cout << "Zombies must be at least one\n";
        return NULL;
    }
    Zombie *z = new Zombie[N];
    int i = -1;
    while (++i < N)
        z[i].set_name(name);
    return z;   
}