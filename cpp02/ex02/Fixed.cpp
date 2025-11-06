#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_bits = 8;

// Constructors and Destructors
Fixed::Fixed(void): val(0) {}

Fixed::Fixed(const Fixed& copy)
{
    this->val = copy.val;
}

Fixed::Fixed(const int i)
{
    this->val = i << fractional_bits;
}

Fixed::Fixed(const float f)
{
    this->val = roundf(f * (1 << fractional_bits));
}

Fixed::~Fixed() {}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& t)
{
    if (this != &t)
        this->val = t.val;
    return *this;
}

// Basic member functions
int Fixed::getRawBits(void) const
{
    return this->val;
}

void Fixed::setRawBits(int const raw)
{
    this->val = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->val / (float)(1 << fractional_bits);
}

int Fixed::toInt(void) const
{
    return this->val >> fractional_bits;
}

// Comparison operators (OPTIMIZED - using direct integer comparison)
bool Fixed::operator>(const Fixed& fixed) const
{
    return (this->val > fixed.val);
}

bool Fixed::operator>=(const Fixed& fixed) const
{
    return (this->val >= fixed.val);
}

bool Fixed::operator<(const Fixed& fixed) const
{
    return (this->val < fixed.val);
}

bool Fixed::operator<=(const Fixed& fixed) const
{
    return (this->val <= fixed.val);
}

bool Fixed::operator==(const Fixed& fixed) const
{
    return (this->val == fixed.val);
}

bool Fixed::operator!=(const Fixed& fixed) const
{
    return (this->val != fixed.val);
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
    Fixed result;
    result.val = this->val + fixed.val;
    return result;
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
    Fixed result;
    result.val = this->val - fixed.val;
    return result;
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
    Fixed result;
    long long temp = (long long)this->val * (long long)fixed.val;
    result.val = temp >> fractional_bits;
    return result;
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
    Fixed result;
    if (fixed.val != 0)
    {
        long long temp = ((long long)this->val << fractional_bits);
        result.val = temp / fixed.val;
    }
    return result;
}


Fixed& Fixed::operator++()
{
    this->val++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->val++;
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
    this->val--;
    return tmp;
}

// Static min/max functions (using if-else)
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