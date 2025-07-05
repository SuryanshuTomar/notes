#include <iostream>

using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // Pointer to the first element of the array
    // Demonstrating pointer arithmetic and array notation with pointers
    cout << "First element address : " << endl;
    cout << arr << endl; // Address of the first element
    cout << &arr[0] << endl; // Address of the first element
    cout << endl;

    int *ptr = arr; // Pointer to the first element of the array

    cout << "Array elements using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " "; // Accessing elements using pointer arithmetic
    }
    cout << endl;

    cout << "Array elements using array notation:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << ptr[i] << " "; // Accessing elements using array notation
    }
    cout << endl;

    return 0;
}