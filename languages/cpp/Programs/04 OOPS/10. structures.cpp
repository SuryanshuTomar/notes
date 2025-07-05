#include <iostream>
#include <string>
using namespace std;

// Define a structure for Student
struct Student {
    string name;
    int age;
    float gpa;
    string major;
};

// Define a structure for Rectangle
struct Rectangle {
    double length;
    double width;
    
    // Member function to calculate area
    double calculateArea() {
        return length * width;
    }
};

int main() {
    // Creating and initializing Student structure
    Student student1;
    student1.name = "John Doe";
    student1.age = 20;
    student1.gpa = 3.75;
    student1.major = "Computer Science";
    
    // Creating Student with initialization list
    Student student2 = {"Jane Smith", 19, 3.92, "Mathematics"};
    
    // Creating Rectangle structure
    Rectangle rect;
    rect.length = 10.5;
    rect.width = 7.2;
    
    // Display student information
    cout << "Student 1 Information:" << endl;
    cout << "Name: " << student1.name << endl;
    cout << "Age: " << student1.age << endl;
    cout << "GPA: " << student1.gpa << endl;
    cout << "Major: " << student1.major << endl << endl;
    
    cout << "Student 2 Information:" << endl;
    cout << "Name: " << student2.name << endl;
    cout << "Age: " << student2.age << endl;
    cout << "GPA: " << student2.gpa << endl;
    cout << "Major: " << student2.major << endl << endl;
    
    // Display rectangle information
    cout << "Rectangle Information:" << endl;
    cout << "Length: " << rect.length << endl;
    cout << "Width: " << rect.width << endl;
    cout << "Area: " << rect.calculateArea() << endl;
    
    return 0;
}