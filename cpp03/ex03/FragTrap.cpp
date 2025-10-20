#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	name = "unknown";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hit_points == 0)
	{
		std::cout << "FragTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
		return;
	}
	if (energy_points == 0)
	{
		std::cout << "FragTrap " << name << " cannot attack because it has no energy points left!" << std::endl;
		return;
	}
	
	energy_points--;
	std::cout << "FragTrap " << name << " powerfully attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a positive high five! ✋" << std::endl;
}