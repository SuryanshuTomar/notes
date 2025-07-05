#include <iostream>
using namespace std;

// Regular functions that will be pointed to
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

// Function that takes another function as parameter
int calculate(int x, int y, int (*operation)(int, int)) {
    return operation(x, y);
}

// Function that returns a function pointer
int (*getOperation(char op))(int, int) {
    switch(op) {
        case '+': return add;
        case '-': return subtract;
        case '*': return multiply;
        default: return nullptr;
    }
}

int main() {
    // Basic function pointer declaration and usage
    int (*funcPtr)(int, int);

    cout << "=== Basic Function Pointer Usage ===" << endl;
    funcPtr = add;
    cout << "5 + 3 = " << funcPtr(5, 3) << endl;
    
    funcPtr = subtract;
    cout << "5 - 3 = " << funcPtr(5, 3) << endl;
    
    funcPtr = multiply;
    cout << "5 * 3 = " << funcPtr(5, 3) << endl;
    
    // Array of function pointers for reusability
    cout << "\n=== Array of Function Pointers ===" << endl;
    int (*operations[])(int, int) = {add, subtract, multiply};
    string opNames[] = {"Addition", "Subtraction", "Multiplication"};
    
    for(int i = 0; i < 3; i++) {
        cout << opNames[i] << ": 8, 4 = " << operations[i](8, 4) << endl;
    }
    
    // Using function pointer as parameter
    cout << "\n=== Function Pointer as Parameter ===" << endl;
    cout << "Calculate (10, 5) with add: " << calculate(10, 5, add) << endl;
    cout << "Calculate (10, 5) with subtract: " << calculate(10, 5, subtract) << endl;
    cout << "Calculate (10, 5) with multiply: " << calculate(10, 5, multiply) << endl;
    
    // Function returning function pointer
    cout << "\n=== Function Returning Function Pointer ===" << endl;
    auto op = getOperation('+');
    if(op) cout << "Dynamic operation (+): 7 + 2 = " << op(7, 2) << endl;
    
    op = getOperation('*');
    if(op) cout << "Dynamic operation (*): 7 * 2 = " << op(7, 2) << endl;
    
    return 0;
}