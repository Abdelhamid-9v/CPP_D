#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
		return;
	}
	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack because it has no energy points left!" << std::endl;
		return;
	}
	
	energy_points--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
		return;
	}
	
	if (amount >= hit_points)
		hit_points = 0;
	else
		hit_points -= amount;
	
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! ";
	std::cout << "It now has " << hit_points << " hit points." << std::endl;
	
	if (hit_points == 0)
		std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " cannot repair itself because it has no hit points left!" << std::endl;
		return;
	}
	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " cannot repair itself because it has no energy points left!" << std::endl;
		return;
	}
	
	energy_points--;
	hit_points += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points! ";
	std::cout << "It now has " << hit_points << " hit points and " << energy_points << " energy points." << std::endl;
}