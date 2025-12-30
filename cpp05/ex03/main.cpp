#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat high("high", 1);

        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

        if (rrf) {
            high.signForm(*rrf);
            high.executeForm(*rrf);
            delete rrf;
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}