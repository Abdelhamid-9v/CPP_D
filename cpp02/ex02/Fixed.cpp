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
    this->val = i << fractional_bits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    this->val = roundf(f * (1 << fractional_bits));
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
    return this->val >> fractional_bits;
}

// Comparison operators
bool Fixed::operator>(const Fixed& fixed) const
{
    return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator>=(const Fixed& fixed) const
{
    return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<(const Fixed& fixed) const
{
    return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator<=(const Fixed& fixed) const
{
    return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(const Fixed& fixed) const
{
    return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed& fixed) const
{
    return (this->toFloat() != fixed.toFloat());
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& fixed) const
{
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
    return Fixed(this->toFloat() / fixed.toFloat());
}

// Increment/Decrement operators
Fixed& Fixed::operator++()
{
    this->val++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++this->val;
    return tmp;
}

Fixed& Fixed::operator--()
{
    this->val--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --this->val;
    return tmp;
}

// Static min/max functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Output stream operator
std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
    o << fixed.toFloat();
    return o;
}