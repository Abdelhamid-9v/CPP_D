#include "Fixed.hpp"

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
