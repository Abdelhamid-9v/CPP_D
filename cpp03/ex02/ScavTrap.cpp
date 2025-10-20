#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	name ="unknown";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_points == 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
		return;
	}
	if (energy_points == 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack because it has no energy points left!" << std::endl;
		return;
	}
	
	energy_points--;
	std::cout << "ScavTrap " << name << " fiercely attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}