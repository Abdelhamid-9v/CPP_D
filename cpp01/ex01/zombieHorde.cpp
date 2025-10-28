#include "Zombie.hpp"

using namespace std;

Zombie* zombieHorde( int N, string name )
{
    if(N < 1)
    {
        cout << "Zombies must be at least one\n";
        return NULL;
    }
    Zombie *z = new Zombie[N];
    if (!z)
    {
        cout << "Allocation failed\n";
        return NULL;
    }
    int i = -1;
    while (++i < N)
        z[i].set_name(name);

    return z;   
    
}