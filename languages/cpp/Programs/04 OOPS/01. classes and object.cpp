#include <iostream>

using namespace std;

class Student {
public:
    string name;
    int age;
    string rollNo;
};

int main() {
    Student student1;
    student1.name = "John Doe";
    student1.age = 20;
    student1.rollNo = "12345";
    
    cout << "Name: " << student1.name << endl;
    cout << "Age: " << student1.age << endl;
    cout << "Roll No: " << student1.rollNo << endl;

    return 0;
}
// This code defines a simple class named Student with three public attributes: name, age, and rollNo.
// In the main function, an instance of Student is created, and its attributes are assigned values.
// Finally, the values of the attributes are printed to the console.