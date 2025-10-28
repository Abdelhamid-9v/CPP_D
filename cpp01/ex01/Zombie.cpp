#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
	std::cout << "A zombie has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}