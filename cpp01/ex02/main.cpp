#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Memory address of str:       " << &str << std::endl;
    std::cout << "Memory address in stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address in stringREF: " << &stringREF << std::endl;

    std::cout << "Value of str:                " << str << std::endl;
    std::cout << "Value pointed by stringPTR:  " << *stringPTR << std::endl;
    std::cout << "Value of stringREF:          " << stringREF << std::endl;

    return 0;
}