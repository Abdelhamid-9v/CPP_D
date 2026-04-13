#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::vector<int>::iterator it1 = easyfind(vec,2);
    if (it1 != vec.end()) {
        std::cout << "found " << *it1 << " in vector." << std::endl;
    } else {
        std::cout << "Error: Value not found in vector." << std::endl;
    }

    std::vector<int>::iterator it2 = easyfind(vec,5);
    if (it2 != vec.end()) {
        std::cout << "found " << *it2 << " in vector." << std::endl;
    } else {
        std::cout << "Error: Value not found in vector." << std::endl;
    }

    ////////////////////////////////////////////////////////////////////////


    std::list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::list<int>::iterator it3 = easyfind(list,3);
    if (it3 != list.end()) {
        std::cout << "found " << *it3 << " in list." << std::endl;
    } else {
        std::cout << "Error: Value not found in list." << std::endl;
    }

    std::list<int>::iterator it4 = easyfind(list,10);
    if (it4 != list.end()) {
        std::cout << "found " << *it4 << " in list." << std::endl;
    } else {
        std::cout << "Error: Value not found in list." << std::endl;
    }
    return 0;
}