#include "Harl.HPP"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log_level>" << std::endl;
        std::cerr << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }

    Harl harl;
    harl.filter(argv[1]);

    return 0;
}