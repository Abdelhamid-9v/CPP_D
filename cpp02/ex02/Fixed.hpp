#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
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
    bool	operator>(const Fixed& fixed) const;
    bool	operator>=(const Fixed& fixed) const;
    bool	operator<(const Fixed& fixed) const;
    bool	operator<=(const Fixed& fixed) const;
    bool	operator==(const Fixed& fixed) const;
    bool	operator!=(const Fixed& fixed) const;
    Fixed operator+(const Fixed& fixed) const;
    Fixed operator-(const Fixed& fixed) const;
    Fixed operator*(const Fixed& fixed) const;
    Fixed operator/(const Fixed& fixed) const;

    Fixed& operator++();    // Pre-increment
    Fixed operator++(int);  // Post-increment
    Fixed& operator--();    // Pre-decrement
    Fixed operator--(int);  // Post-decrement

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif