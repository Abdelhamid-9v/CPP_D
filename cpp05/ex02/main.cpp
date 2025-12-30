#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    // Seed random for Robotomy
    std::srand(std::time(0));

    try {
        Bureaucrat high("high", 1);
        Bureaucrat low("low", 140);
        
        ShrubberyCreationForm shrub("llll");
        RobotomyRequestForm robot("mmmm");
        PresidentialPardonForm pardon("hhhh");

        std::cout << "\n--- SHRUBBERY TEST ---" << std::endl;
        low.signForm(shrub);
        std::cout << "_________________\n";
        low.executeForm(shrub);
        std::cout << "_________________\n";
        high.executeForm(shrub);

        std::cout << "\n--- ROBOTOMY TEST ---" << std::endl;
        high.signForm(robot);
        std::cout << "_________________\n";
        low.executeForm(robot);
        std::cout << "_________________\n";
        high.executeForm(robot);

        std::cout << "\n--- PARDON TEST ---" << std::endl;
        high.signForm(pardon);
        high.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}