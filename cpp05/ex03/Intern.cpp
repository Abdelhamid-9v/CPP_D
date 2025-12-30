#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

// --- Helper Functions to create specific forms ---
// These are static because they don't need the Intern object to work
static AForm* makeShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

static AForm* makePardon(std::string target) {
    return new PresidentialPardonForm(target);
}

// --- The Main Function ---
AForm* Intern::makeForm(std::string formName, std::string target) {
    // 1. Array of Form Names
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // 2. Array of Pointers to the Helper Functions above
    // Syntax: ReturnType (*ArrayName[])(Parameters)
    AForm* (*formCreators[])(std::string target) = {
        &makeShrubbery,
        &makeRobotomy,
        &makePardon
    };

    // 3. Loop to find a match
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            // Call the function at index i
            return formCreators[i](target);
        }
    }

    // 4. If loop finishes without return, the form doesn't exist
    std::cout << "Intern cannot create " << formName << " because it doesn't exist." << std::endl;
    return NULL;
}