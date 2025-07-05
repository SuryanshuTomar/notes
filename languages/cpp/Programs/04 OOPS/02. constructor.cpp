#include <iostream>

using namespace std;

class Student {
public:
    string name;
    int age;
    string rollNo;

    // Constructor to initialize the attributes
    Student(string name, int age, string rollNo) 
        :name(name), age(age), rollNo(rollNo) {
            cout << "Constructor called!" << endl;
    }   
};

int main() {
    // Creating an object of Student class using the constructor
    Student student1("John Doe", 20, "12345");
    cout << "Name: " << student1.name << endl;
    cout << "Age: " << student1.age << endl;
    cout << "Roll No: " << student1.rollNo << endl;

    return 0;
}