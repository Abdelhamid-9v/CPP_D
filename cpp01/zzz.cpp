#include <iostream>
#include <string>

class Test {
private:
    std::string data;
public:
    void withReference(const std::string& str) {
        data = str;
        std::cout << "Reference version - param address: " << &str << std::endl;
    }
    
    void withoutReference(const std::string str) {
        data = str;
        std::cout << "Value version - param address: " << &str << std::endl;
    }
};

int main() {
    Test test;
    std::string myString = "Hello World";
    
    std::cout << "Original string address: " << &myString << std::endl;
    
    test.withReference(myString);    // Same address as original
    test.withoutReference(myString); // DIFFERENT address - it's a copy
}