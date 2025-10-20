// CPP Program to demonstrate the use of copy constructor
// and assignment operator
#include <iostream>
#include <stdio.h>
using namespace std;

class Test {
public:
    Test() {}
    Test(const Test& t)
    {
        cout << "Copy constructor called " << endl;
    }
    // Test&  opera
    Test& operator=(const Test& t)
    {
        cout << "Assignment operator called " << endl;
        return *this;
    }
};

// Driver code
int main()
{
    std::ostream << "jjjjjjjjjjjj\n";

    return 0;
}