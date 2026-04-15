#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }

    BitcoinExchange btc;
    btc.process_input(av[1]);

    return 0;
}