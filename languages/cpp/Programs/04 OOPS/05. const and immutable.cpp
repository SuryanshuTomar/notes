#include <iostream>

using namespace std;

class Student {
private:
    const int rollNo;
    string name;
    mutable int accessCount; // mutable allows modification even in const methods
    mutable bool isModified;
    
public:
    Student(int rollNo, string name) : rollNo(rollNo), name(name), accessCount(0), isModified(false) {
        // Constructor initializes all members including mutable ones
    }
    
    int getRollNo() const {
        accessCount++; // Can modify mutable member in const method
        return rollNo;
    }
    
    string getName() const {
        accessCount++; // Can modify mutable member in const method
        return name;
    }
    
    void setName(const string& newName) {
        name = newName;
        isModified = true; // Can modify mutable member in non-const method
    }
    
    void display() const {
        accessCount++; // Can modify mutable member in const method
        cout << "Roll No: " << rollNo << ", Name: " << name 
             << " (Accessed: " << accessCount << " times)" << endl;
    }
    
    int getAccessCount() const {
        return accessCount; // const method returning mutable member
    }
    
    bool hasBeenModified() const {
        return isModified; // const method returning mutable member
    }
};

int main() {
    const Student student1(101, "Alice"); // const object
    Student student2(102, "Bob");
    const Student student3(103, "Charlie"); // const object
    
    // const objects can only call const methods
    student1.display();
    student2.display();
    student3.display();
    
    student2.setName("Robert"); // Only non-const object can call non-const methods
    cout << "After changing name of student2:" << endl;
    student1.display();
    student2.display();
    student3.display();

    // const objects can access mutable members through const methods
    cout << "Roll No of student1: " << student1.getRollNo() << endl;
    cout << "Name of student1: " << student1.getName() << endl;
    cout << "Access count for student1: " << student1.getAccessCount() << endl;
    cout << "Student1 modified: " << student1.hasBeenModified() << endl;
    
    cout << "Roll No of student2: " << student2.getRollNo() << endl;
    cout << "Name of student2: " << student2.getName() << endl;
    cout << "Access count for student2: " << student2.getAccessCount() << endl;
    cout << "Student2 modified: " << student2.hasBeenModified() << endl;
    
    return 0;
}