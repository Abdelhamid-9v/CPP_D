#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <iostream>
#include <stack>

class RPN {
    public:
    RPN();
    RPN(const RPN& copy);
    RPN& operator=(const RPN& assign);
    ~RPN();


    static int calc(char *str);
};

#endif