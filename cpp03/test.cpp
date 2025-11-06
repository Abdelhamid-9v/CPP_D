#include<iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() override{  // Not overriding, just hiding
        cout << "Dog barks\n";
    }
};

int main() {
    Animal* a = new Dog();
    a->sound();  // Output: Animal sound
}