#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data bob;
    bob.name = "abel-had";
    bob.age = 42;
    bob.role = "Manager";

    std::cout << "Original Address: " << &bob << std::endl;
    std::cout << "Original Name: " << bob.name << std::endl;

    uintptr_t raw_data = Serializer::serialize(&bob);
    std::cout << "Serialized (id_code): " << raw_data << std::endl;

    Data* ptr = Serializer::deserialize(raw_data);
    std::cout << "Restored Address: " << ptr << std::endl;
    std::cout << "Restored Name: " << ptr->name << std::endl;

    if (ptr == &bob)
    {
        std::cout << "Success: The pointers match!" << std::endl;
    }
    else
    {
        std::cout << "Error: The pointers do not match." << std::endl;
    }

    return 0;
}