#include "iter.hpp"
#include <string>

template <typename T>
void print_element(T x)
{
    std::cout << x << " ";
}

void increment(int & x)
{
    x++;
}

int main() {

    int intArray[] = {0, 1, 2, 3, 4};
    std::cout << "original int array: ";
    iter(intArray, 5, print_element<int>);
    std::cout << std::endl;

    iter(intArray, 5, increment);

    std::cout << "incremented int array: ";
    iter(intArray, 5, print_element<int>);
    std::cout << std::endl;

    return 0;
}