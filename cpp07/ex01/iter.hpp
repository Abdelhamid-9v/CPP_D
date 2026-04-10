#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void iter(T *arr, const size_t l, F func)
{
    if (!arr || !func)
        return;
    for (size_t i = 0; i < l; i++)
        func(arr[i]);
}

#endif