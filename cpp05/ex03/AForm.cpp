#include "AForm.hpp"

AForm::AForm() : name("Default"), is_signed(false), grade_to_sign(150), grade_to_execute(150) {}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute) 
    : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) {
    if (grade_to_sign < 1 || grade_to_execute < 1) throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm &other) 
    : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        is_signed = other.is_signed;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return name; }
bool        AForm::getSigned() const { return is_signed; }
int         AForm::getGradeToSign() const { return grade_to_sign; }
int         AForm::getGradeToExecute() const { return grade_to_execute; }

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > grade_to_sign)
        throw GradeTooLowException();
    is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() { return "Grade too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Grade too low!"; }
const char* AForm::FormNotSignedException::what() const throw() { return "Form is not signed!"; }

std::ostream &operator<<(std::ostream &os, const AForm &f) {
    os << "Form: " << f.getName() << " | Signed: ";
    
    if (f.getSigned())
        os << "Yes";
    else
        os << "No";
    
    os << " | Sign Grade: " << f.getGradeToSign() 
       << " | Exec Grade: " << f.getGradeToExecute();
    
    return os;
}