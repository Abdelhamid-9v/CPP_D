#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat high("high", 1);
        Bureaucrat low("low", 150);
        
        Form form("Tax_form", 50, 20);

        std::cout << form << std::endl;

        low.signForm(form);
        std::cout << form << std::endl;

        high.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}