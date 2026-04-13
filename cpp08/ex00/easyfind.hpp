#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include<algorithm>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T& var, int a)
{
    return std::find(var.begin(),var.end(),a);
}


#endif