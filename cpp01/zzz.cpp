#include <iostream>
#include <string>
#include <fstream>

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
    
   std::ofstream outf;

   outf.open(myString);
}