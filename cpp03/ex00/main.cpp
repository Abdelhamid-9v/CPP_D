#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap clap1("____1____");
	ClapTrap clap2("____2____");
	
	std::cout << "\n=== Testing attacks ===" << std::endl;
	clap1.attack("____2____");
	clap2.attack("____1____");
	
	std::cout << "\n=== Testing damage and repair ===" << std::endl;
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	clap1.takeDamage(10);
	
	std::cout << "\n=== Testing energy consumption ===" << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << "Action " << i + 1 << ": ";
		clap2.attack("someone");
	}
	
	std::cout << "\n=== Testing edge cases ===" << std::endl;
	clap1.attack("____2____");     // should fail no hit points
	clap1.beRepaired(5);           // should fail no hit points
	clap2.beRepaired(5);           // should fail no energy points
	
	std::cout << "\n=== Testing copy constructor and assignment ===" << std::endl;
	ClapTrap clap3(clap1);
	ClapTrap clap4;
	clap4 = clap2;
	
	std::cout << "\n=== End of scope - destructors called ===" << std::endl;
	return 0;
}