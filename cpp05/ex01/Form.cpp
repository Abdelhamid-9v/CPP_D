#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : name("Default"), sign(false), si_grade(150), exe_grade(150) {
}

Form::Form(const std::string &name, int si_grade, int exe_grade) 
    : name(name), sign(false), si_grade(si_grade), exe_grade(exe_grade)
{
    if (si_grade < 1 || exe_grade < 1)
        throw Form::GradeTooHighException();
    if (si_grade > 150 || exe_grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other) 
    : name(other.name), sign(other.sign), si_grade(other.si_grade), exe_grade(other.exe_grade) {
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->sign = other.sign;
    }
    return *this;
}

Form::~Form() {
}

std::string Form::getName() const { 
    return name; 
}

bool Form::getSign() const { 
    return sign; 
}

int Form::getSiGrade() const { 
    return si_grade; 
}

int Form::getExeGrade() const { 
    return exe_grade; 
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > si_grade)
    {
        throw Form::GradeTooLowException();
    }
    sign = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form: " << f.getName() << " | Signed: ";
    if (f.getSign()) {
        os << "Yes";
    } else {
        os << "No";
    }
    os << " | Required to Sign: " << f.getSiGrade()
       << " | Required to Execute: " << f.getExeGrade();

    return os;
}