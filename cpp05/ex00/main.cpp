#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        std::cout << "trying to increment again (this should fail)..." << std::endl;
        bob.incrementGrade(); 
        
        std::cout << "this line will not run." << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}