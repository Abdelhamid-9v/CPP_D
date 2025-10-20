#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== DIAMONDTRAP CONSTRUCTION/DESTRUCTION CHAINING ===" << std::endl;
	{
		std::cout << "\n--- Creating DiamondTrap inside block ---" << std::endl;
		DiamondTrap diamond("DI4M0ND");
		std::cout << "\n--- End of block - destruction should occur ---" << std::endl;
	}
	
	std::cout << "\n=== TESTING DIAMONDTRAP FUNCTIONALITY ===" << std::endl;
	DiamondTrap diamond1("Sparkles");
	DiamondTrap diamond2("Shiny");
	
	std::cout << "\n--- Testing whoAmI() special ability ---" << std::endl;
	diamond1.whoAmI();
	diamond2.whoAmI();
	
	std::cout << "\n--- Testing inherited attack method (from ScavTrap) ---" << std::endl;
	diamond1.attack("Target Dummy");
	diamond2.attack("Practice Bot");
	
	std::cout << "\n--- Testing inherited abilities from both parents ---" << std::endl;
	diamond1.guardGate();    // From ScavTrap
	diamond1.highFivesGuys(); // From FragTrap
	
	std::cout << "\n--- Testing DiamondTrap mixed stats ---" << std::endl;
	std::cout << "HP: " << diamond1.getHitPoints() << " (from FragTrap)" << std::endl;
	std::cout << "Energy: " << diamond1.getEnergyPoints() << " (from ScavTrap)" << std::endl;
	std::cout << "Damage: " << diamond1.getAttackDamage() << " (from FragTrap)" << std::endl;
	
	diamond1.takeDamage(70);
	diamond1.beRepaired(25);
	diamond1.takeDamage(60);
	
	std::cout << "\n--- Testing energy consumption (ScavTrap's 50 energy) ---" << std::endl;
	for (int i = 0; i < 55; i++)
	{
		std::cout << "Action " << i + 1 << ": ";
		if (i % 2 == 0)
			diamond2.attack("enemy");
		else
			diamond2.beRepaired(5);
	}
	
	std::cout << "\n=== TESTING COPY CONSTRUCTOR AND ASSIGNMENT ===" << std::endl;
	DiamondTrap diamond3(diamond1);
	DiamondTrap diamond4("TempName");
	diamond4 = diamond2;
	
	std::cout << "\n--- Copied objects should maintain their names ---" << std::endl;
	diamond3.whoAmI();
	diamond4.whoAmI();
	
	std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
	ClapTrap* base1 = new ScavTrap("ScavBase");
	ClapTrap* base2 = new FragTrap("FragBase"); 
	ClapTrap* base3 = new DiamondTrap("DiamondBase");
	
	std::cout << "\n--- Polymorphic behavior ---" << std::endl;
	base1->attack("target");
	base2->attack("target");
	base3->attack("target");
	
	delete base1;
	delete base2;
	delete base3;
	
	std::cout << "\n=== COMPREHENSIVE DIAMONDTRAP TEST ===" << std::endl;
	DiamondTrap ultimate("Ultimate");
	ultimate.whoAmI();
	ultimate.guardGate();
	ultimate.highFivesGuys();
	ultimate.attack("final boss");
	ultimate.takeDamage(99);
	ultimate.beRepaired(50);
	ultimate.highFivesGuys();
	
	std::cout << "\n=== END OF SCOPE - ALL DESTRUCTORS CALLED ===" << std::endl;
	return 0;
}