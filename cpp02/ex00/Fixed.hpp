#ifndef FIXED_HPP
#define FIXED_HPP


#include <string>
#include <iostream>


class  Fixed
{
private:
    int val;
    static const int  fractional_bits;
public:
    Fixed(void);
    Fixed(const Fixed& copy);
    ~ Fixed();

    Fixed& operator=(const Fixed& t);
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};




#endif