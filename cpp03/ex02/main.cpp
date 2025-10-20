#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== CONSTRUCTION/DESTRUCTION CHAINING ===" << std::endl;
	{
		std::cout << "\n--- Creating FragTrap inside block ---" << std::endl;
		FragTrap frag("FR4G-TP");
		std::cout << "\n--- End of block - destruction should occur ---" << std::endl;
	}
	
	std::cout << "\n=== TESTING FRAGTRAP FUNCTIONALITY ===" << std::endl;
	FragTrap frag1("Boomer");
	FragTrap frag2("Sploder");
	
	std::cout << "\n--- Testing overridden attack method ---" << std::endl;
	frag1.attack("Target Dummy");
	frag2.attack("Practice Bot");
	
	std::cout << "\n--- Testing special ability ---" << std::endl;
	frag1.highFivesGuys();
	frag2.highFivesGuys();
	
	std::cout << "\n--- Testing FragTrap stats (100 HP, 100 Energy, 30 Damage) ---" << std::endl;
	frag1.takeDamage(70);
	frag1.beRepaired(20);
	frag1.takeDamage(60); // Should have 100 - 70 + 20 - 60 = -10? Handled properly
	
	std::cout << "\n--- Testing energy consumption with high energy pool ---" << std::endl;
	for (int i = 0; i < 105; i++)
	{
		std::cout << "Action " << i + 1 << ": ";
		if (i % 4 == 0)
			frag2.attack("enemy");
		else if (i % 4 == 1)
			frag2.beRepaired(10);
		else if (i % 4 == 2)
			frag2.highFivesGuys();
		else
			frag2.takeDamage(5);
	}
	
	std::cout << "\n=== TESTING ALL THREE CLASSES TOGETHER ===" << std::endl;
	ClapTrap clap("CL4P");
	ScavTrap scav("SC4V");
	FragTrap frag("FR4G");
	
	std::cout << "\n--- Each class using their attack method ---" << std::endl;
	clap.attack("target");
	scav.attack("target");
	frag.attack("target");
	
	std::cout << "\n--- Special abilities ---" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	
	std::cout << "\n=== TESTING COPY AND ASSIGNMENT FOR FRAGTRAP ===" << std::endl;
	FragTrap frag3(frag1);
	FragTrap frag4;
	frag4 = frag2;
	
	std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
	ClapTrap* traps[3];
	traps[0] = new ClapTrap("BaseClap");
	traps[1] = new ScavTrap("DerivedScav");
	traps[2] = new FragTrap("DerivedFrag");
	
	std::cout << "\n--- Polymorphic attack calls ---" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		traps[i]->attack("polymorphic target");
		delete traps[i];
	}
	
	std::cout << "\n=== END OF SCOPE - ALL DESTRUCTORS CALLED ===" << std::endl;
	return 0;
}