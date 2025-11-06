#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>

class Fixed
{
private:
    int val;
    static const int fractional_bits;
    
public:
    Fixed(void);
    Fixed(const int i);
    Fixed(const float f);
    Fixed(const Fixed& copy);
    ~Fixed();

    Fixed& operator=(const Fixed& t);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif