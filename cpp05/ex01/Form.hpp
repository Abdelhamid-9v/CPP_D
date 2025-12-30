#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"


class Bureaucrat;

class Form {
private:
    const std::string   name;
    bool                sign;
    const int           si_grade;
    const int           exe_grade;

public:
    Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    Form(const std::string &name, int si_grade, int exe_grade);

    std::string getName() const;
    bool        getSign() const;
    int         getSiGrade() const;
    int         getExeGrade() const;

    void        beSigned(const Bureaucrat &b);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif