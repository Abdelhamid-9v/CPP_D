#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== CONSTRUCTION/DESTRUCTION CHAINING ===" << std::endl;
	{
		std::cout << "\n--- Creating ScavTrap inside block ---" << std::endl;
		ScavTrap scav("___1___");
		std::cout << "\n--- End of block - destruction should occur ---" << std::endl;
	}
	
	std::cout << "\n=== TESTING SCAVTRAP FUNCTIONALITY ===" << std::endl;
	ScavTrap scav1("___2___");
	ScavTrap scav2("___3___");
	
	std::cout << "\n--- Testing overridden attack method ---" << std::endl;
	scav1.attack("Enemy1");
	scav2.attack("Enemy2");
	
	std::cout << "\n--- Testing special ability ---" << std::endl;
	scav1.guardGate();
	scav2.guardGate();
	
	std::cout << "\n--- Testing ScavTrap stats ---" << std::endl;
	scav1.takeDamage(30);
	scav1.beRepaired(15);
	scav1.takeDamage(90);
	
	
	std::cout << "\n=== TESTING COPY AND ASSIGNMENT ===" << std::endl;
	ScavTrap scav3(scav1);
	ScavTrap scav4;
	scav4 = scav2;
	
	std::cout << "\n=== END OF SCOPE - ALL DESTRUCTORS CALLED ===" << std::endl;
	return 0;
}