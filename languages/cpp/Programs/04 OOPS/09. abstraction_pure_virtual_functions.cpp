#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Animal {
    public:
        virtual void sound() = 0; // Pure virtual function
        // The "= 0" syntax indicates that this is a pure virtual function, making Animal an abstract class.
        // Any class that inherits from Animal must provide an implementation for the sound() function.

        virtual ~Animal() = default; // Virtual destructor for proper cleanup
        // Note: The destructor is virtual to ensure that derived class destructors are called correctly
        // here default is used to provide a default implementation
        // This allows us to avoid defining an empty destructor in the base class.

        void info() {
            cout << "This is an animal.\n" << endl;
        }
};

class Dog: public Animal {
    public:
        Dog() {
            cout << "Dog constructor called" << endl;
        }
        void sound() override {
            cout << "Woof Woof" << endl;
        }
};

class Cat: public Animal {
    public:
        Cat() {
            cout << "Cat constructor called" << endl;
        }
        void sound() override {
            cout << "Meow Meow" << endl;
        }

};

class Cow: public Animal {
    public:
        Cow() {
            cout << "Cow constructor called" << endl;
        }
        void sound() override {
            cout << "Moo Moo" << endl;
        }
};

class Tiger: public Animal {
    public:
        Tiger() {
            cout << "Tiger constructor called" << endl;
        }
        void sound() override {
            cout << "Roar Roar" << endl;
        }
};

int main() {
    // using unique_ptr for automatic memory management
    vector<unique_ptr<Animal>> animals;
    animals.push_back(make_unique<Dog>());
    animals.push_back(make_unique<Cat>());
    animals.push_back(make_unique<Cow>());
    animals.push_back(make_unique<Tiger>());

    for_each(animals.begin(), animals.end(), [](const unique_ptr<Animal>& animal) {
        animal->sound(); // Calls the pure virtual function
        animal->info();  // Calls the non-virtual function
    });

    // No manual cleanup needed - unique_ptr handles memory management automatically
    // The destructors of Dog, Cat, Cow, and Tiger will be called automatically when the vector goes out of scope
    return 0;
}