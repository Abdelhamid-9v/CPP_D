#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	std::string name = "Jilali";

    std::cout << "================================================" << std::endl;
	std::cout << "=== Creating a horde of " << N << " zombies ===" << std::endl;
    std::cout << "================================================" << std::endl;

	Zombie* horde = zombieHorde(N, name);

	if (!horde)
	{
		std::cout << "Failed to create zombie horde" << std::endl;
		return 1;
	}

	std::cout << "\n=== Zombies announcing themselves ===" << std::endl;
	for (int i = 0; i < N; i++)
	{   
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}

	std::cout << "\n=== Destroying the horde ===" << std::endl;
	delete[] horde;

	std::cout << "\n=== Testing edge cases ===" << std::endl;
	Zombie* invalid = zombieHorde(0, "invalid");
	if (!invalid)
		std::cout << "Correctly handled invalid horde size" << std::endl;

	std::cout << "\n=== Creating a single zombie horde ===" << std::endl;
	Zombie* single = zombieHorde(1, "sidna khat a7mar");
	if (single)
	{
		single->announce();
		delete[] single;
	}

	return 0;
}