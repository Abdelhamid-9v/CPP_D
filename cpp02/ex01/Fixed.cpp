#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_bits = 8;


Fixed::Fixed(void) : val(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->val = copy.val;
}


Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    this->val = i << fractional_bits; // i * 256
}


Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    this->val = roundf(f * (1 << fractional_bits)); // f * 256
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


Fixed& Fixed::operator=(const Fixed& t)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &t)
        this->val = t.val;
    return *this;
}


float Fixed::toFloat(void) const
{
    return (float)val / (1 << fractional_bits);
}


int Fixed::toInt(void) const
{
    return val >> fractional_bits;
}


std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
    o << fixed.toFloat();
    return o;
}
