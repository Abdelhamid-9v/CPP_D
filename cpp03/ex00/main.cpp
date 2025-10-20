#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap clap1("CL4P-TP");
	ClapTrap clap2("B4D-4SS");
	
	std::cout << "\n=== Testing attacks ===" << std::endl;
	clap1.attack("B4D-4SS");
	clap2.attack("CL4P-TP");
	
	std::cout << "\n=== Testing damage and repair ===" << std::endl;
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	clap1.takeDamage(10);
	
	std::cout << "\n=== Testing energy consumption ===" << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << "Action " << i + 1 << ": ";
		clap2.attack("target");
	}
	
	std::cout << "\n=== Testing edge cases ===" << std::endl;
	clap1.attack("B4D-4SS"); // Should fail - no hit points
	clap1.beRepaired(5);     // Should fail - no hit points
	clap2.beRepaired(5);     // Should fail - no energy points
	
	std::cout << "\n=== Testing copy constructor and assignment ===" << std::endl;
	ClapTrap clap3(clap1);
	ClapTrap clap4;
	clap4 = clap2;
	
	std::cout << "\n=== End of scope - destructors called ===" << std::endl;
	return 0;
}