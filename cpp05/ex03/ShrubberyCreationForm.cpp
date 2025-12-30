#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream outfile((target + "_shrubbery").c_str());
    if (outfile.is_open()) {
        outfile << "       _-_" << std::endl;
        outfile << "    /~~   ~~\\" << std::endl;
        outfile << " /~~         ~~\\" << std::endl;
        outfile << "{               }" << std::endl;
        outfile << " \\  _-     -_  /" << std::endl;
        outfile << "   ~  \\\\ //  ~" << std::endl;
        outfile << "_- -   | | _- _" << std::endl;
        outfile << "  _ -  | |   -_" << std::endl;
        outfile << "      // \\\\" << std::endl;
        outfile.close();
    }
}