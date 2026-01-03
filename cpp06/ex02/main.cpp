#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    int random = std::rand() % 3;

    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

#include <iostream>
#include <exception> // Required to use std::exception

// ... (Base, A, B, C classes) ...

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
        (void)e;
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
        (void)e;
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
        (void)e;
    }
}

int main()
{
    std::srand(std::time(NULL));

    std::cout << "--- Test 1 ---" << std::endl;
    Base* ptr1 = generate();
    std::cout << "Pointer identify: ";
    identify(ptr1);
    std::cout << "Reference identify: ";
    identify(*ptr1);
    delete ptr1;

    std::cout << "\n--- Test 2 ---" << std::endl;
    Base* ptr2 = generate();
    std::cout << "Pointer identify: ";
    identify(ptr2);
    std::cout << "Reference identify: ";
    identify(*ptr2);
    delete ptr2;

    std::cout << "\n--- Test 3 ---" << std::endl;
    Base* ptr3 = generate();
    std::cout << "Pointer identify: ";
    identify(ptr3);
    std::cout << "Reference identify: ";
    identify(*ptr3);
    delete ptr3;

    return 0;
}