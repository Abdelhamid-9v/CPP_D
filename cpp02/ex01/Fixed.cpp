#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_bits = 8;

Fixed::Fixed(void): val(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->val = copy.getRawBits();
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    this->val = i << fractional_bits; // or just use i * 256
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

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->val;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->val = raw;
}

Fixed& Fixed::operator=(const Fixed& t)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &t)
        this->val = t.getRawBits();
    return *this;
}

float Fixed::toFloat(void) const
{
    return (float)this->val / (float)(1 << fractional_bits);
}

int Fixed::toInt(void) const
{
    return this->val >> fractional_bits;// or / 256
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
    o << fixed.toFloat();
    return o;
}