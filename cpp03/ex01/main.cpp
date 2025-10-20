#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== CONSTRUCTION/DESTRUCTION CHAINING ===" << std::endl;
	{
		std::cout << "\n--- Creating ScavTrap inside block ---" << std::endl;
		ScavTrap scav("SC4V-TP");
		std::cout << "\n--- End of block - destruction should occur ---" << std::endl;
	}
	
	std::cout << "\n=== TESTING SCAVTRAP FUNCTIONALITY ===" << std::endl;
	ScavTrap scav1("Guardian");
	ScavTrap scav2("Protector");
	
	std::cout << "\n--- Testing overridden attack method ---" << std::endl;
	scav1.attack("Intruder");
	scav2.attack("Enemy");
	
	std::cout << "\n--- Testing special ability ---" << std::endl;
	scav1.guardGate();
	scav2.guardGate();
	
	std::cout << "\n--- Testing ScavTrap stats ---" << std::endl;
	scav1.takeDamage(30);
	scav1.beRepaired(15);
	scav1.takeDamage(90); // Should have 100 - 30 + 15 - 90 = -5? No, should handle properly
	
	std::cout << "\n--- Testing energy consumption ---" << std::endl;
	for (int i = 0; i < 55; i++)
	{
		std::cout << "Action " << i + 1 << ": ";
		if (i % 3 == 0)
			scav2.attack("target");
		else if (i % 3 == 1)
			scav2.beRepaired(5);
		else
			scav2.guardGate();
	}
	
	std::cout << "\n=== TESTING COPY AND ASSIGNMENT ===" << std::endl;
	ScavTrap scav3(scav1);
	ScavTrap scav4;
	scav4 = scav2;
	
	std::cout << "\n=== TESTING POLYMORPHISM WITH CLAPTRAP POINTER ===" << std::endl;
	ClapTrap* clapPtr = new ScavTrap("Polymorphic");
	clapPtr->attack("test"); // Should call ScavTrap's attack
	delete clapPtr;
	
	std::cout << "\n=== END OF SCOPE - ALL DESTRUCTORS CALLED ===" << std::endl;
	return 0;
}