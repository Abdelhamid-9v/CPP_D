#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== CONSTRUCTION/DESTRUCTION CHAINING ===" << std::endl;
	{
		std::cout << "\n--- Creating FragTrap inside block ---" << std::endl;
		FragTrap frag("___0___");
		std::cout << "\n--- End of block - destruction should occur ---" << std::endl;
	}
	
	std::cout << "\n=== TESTING FRAGTRAP FUNCTIONALITY ===" << std::endl;
	FragTrap frag1("___1___");
	FragTrap frag2("___2___");
	
	std::cout << "\n--- Testing overridden attack method ---" << std::endl;
	frag1.attack("enemy1");
	frag2.attack("enemy2");
	
	std::cout << "\n--- Testing special ability ---" << std::endl;
	frag1.highFivesGuys();
	frag2.highFivesGuys();
	
	std::cout << "\n--- Testing FragTrap stats (100 HP, 100 Energy, 30 Damage) ---" << std::endl;
	frag1.takeDamage(70);
	frag1.beRepaired(20);
	frag1.takeDamage(60);
	
	std::cout << "\n--- Testing energy consumption with high energy pool ---" << std::endl;
	for (int i = 0; i < 105; i++)
	{
		frag2.attack("enemy");
		frag2.beRepaired(10);
		frag2.highFivesGuys();
		frag2.takeDamage(5);
	}
	
	std::cout << "\n=== TESTING ALL THREE CLASSES TOGETHER ===" << std::endl;
	ClapTrap clap("___11___");
	ScavTrap scav("___22___");
	FragTrap frag("___33___");
	
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


	std::cout << "\n=== END OF SCOPE - ALL DESTRUCTORS CALLED ===" << std::endl;
	return 0;
}