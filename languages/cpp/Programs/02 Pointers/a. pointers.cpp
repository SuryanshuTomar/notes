#include <iostream>

using namespace std;

int main() {
    // -----------------------------------------------------
    // Example of pointers
    int x = 5;
    
    // Here we are using the address of operator (&) to get the address of x and store it in ptr
    // ptr is a pointer to x, pointer is created using the * operator
    // The type of ptr is int* which means it is a pointer to an integer
    int* ptr = &x;

    cout << "---------------------------------------------" << endl;
    cout << "Value of x: " << x << endl; // Value of x
    cout << "Address of x: " << &x << endl; // Address of x
    cout << "Value of p: " << ptr << endl; // This is also the address of x
    cout << "Value pointed to by ptr: " << *ptr << endl; // This is called dereferencing and dereferencing a pointer gives the value stored at that address
    cout << "Address of ptr: " << &ptr << endl; // Address of the pointer itself
    cout << "---------------------------------------------" << endl;

    // -----------------------------------------------------
    // Another example of pointers
    int a = 10;
    int b = 20;

    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    cout << endl;

    // Pointer to a
    int *p = &a;

    cout << "p : pointer of value a : " << p << endl;
    cout << "*p : value of a after dereferencing pointer p : " << *p << endl;
    cout << endl;

    // Pointer to b
    int *q = &b;

    cout << "q : pointer of b : " << q << endl;
    cout << "*q : value of b after dereferencing pointer q : " << *q << endl;
    cout << endl;
    
    // Pointer to pointer
    int **pp = &p;
    
    cout << "pp : pointer of (pointer p) : " << pp << endl;
    cout << "*pp : value of (pointer p) after dereferencing pointer of (pointer p) : " << *pp << endl;
    cout << "**pp : value of a after dereferencing the deferenced (pointer p)" << **pp << endl;
    cout << "---------------------------------------------" << endl;
    
    
    // -----------------------------------------------------
    // Another example of pointers
    int y = 10;
    int z = 20;
    
    cout << "Before swapping: " << endl;
    cout << "a: " << y << ", b: " << z << endl;
    
    // Swapping using pointers
    int* p1 = &a;
    int* p2 = &b;
    
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    
    cout << "After swapping: " << endl;
    cout << "y: " << y << ", z: " << z << endl;
    
    cout << "---------------------------------------------" << endl;
    return 0;
}