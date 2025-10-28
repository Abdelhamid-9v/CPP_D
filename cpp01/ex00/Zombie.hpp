#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>


class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string Zname){name = Zname;}
    ~Zombie();
    void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif