#include <iostream>

using namespace std;

int main () {
    int x = 10;
    int y = 20;

    // Declare void pointers
    void *ptr1 = &x; // Pointer to int
    void *ptr2 = &y; // Pointer to int

    // Cast void pointers to int pointers and dereference them
    cout << "Value of x: " << *(static_cast<int*>(ptr1)) << endl;
    cout << "Value of y: " << *(static_cast<int*>(ptr2)) << endl;

    return 0;
}