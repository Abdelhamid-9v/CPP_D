#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() 
{
	name = "Default";
	ClapTrap::name = name + "_clap_name";
	hit_points = 100;       // From FragTrap
	energy_points = 50;     // From ScavTrap  
	attack_damage = 30;     // From FragTrap
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	hit_points = 100;       // From FragTrap
	energy_points = 50;     // From ScavTrap
	attack_damage = 30;     // From FragTrap
	std::cout << "DiamondTrap " << this->name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
		ClapTrap::name = other.ClapTrap::name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}