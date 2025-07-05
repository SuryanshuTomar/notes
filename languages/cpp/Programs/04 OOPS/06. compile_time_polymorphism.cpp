#include <iostream>
#include <string>
using namespace std;

// Demonstration of Function Overloading (Compile-time Polymorphism)
class Calculator {
public:
    // Same function name, different parameter types and counts
    int add(int a, int b) {
        cout << "Adding two integers: ";
        return a + b;
    }
    
    double add(double a, double b) {
        cout << "Adding two doubles: ";
        return a + b;
    }
    
    int add(int a, int b, int c) {
        cout << "Adding three integers: ";
        return a + b + c;
    }
    
    string add(string a, string b) {
        cout << "Concatenating strings: ";
        return a + b;
    }
    
    // Different parameter order
    string add(string str, int num) {
        cout << "Adding string and number: ";
        return str + to_string(num);
    }
};

// Demonstration of Operator Overloading
class Point {
private:
    int x, y;
    
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // Overload + operator
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    
    // Overload - operator
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
    
    // Overload == operator
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }
    
    // Overload << operator for output
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    
    // Overload prefix ++ operator
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }
    
    // Overload postfix ++ operator
    Point operator++(int) {
        Point temp = *this;
        ++x;
        ++y;
        return temp;
    }
    
    // Getter methods
    int getX() const { return x; }
    int getY() const { return y; }
};

int main() {
    cout << "=== COMPILE-TIME POLYMORPHISM DEMO ===" << endl;
    cout << "=======================================\n" << endl;
    
    // Function Overloading Demo
    cout << "--- Function Overloading ---" << endl;
    Calculator calc;
    
    cout << calc.add(5, 10) << endl;                    // int version
    cout << calc.add(3.5, 2.8) << endl;                // double version
    cout << calc.add(1, 2, 3) << endl;                 // three-parameter version
    cout << calc.add("Hello", "World") << endl;        // string version
    cout << calc.add("Count: ", 42) << endl;           // string + int version
    
    cout << "\n--- Operator Overloading ---" << endl;
    
    // Create points
    Point p1(3, 4);
    Point p2(1, 2);
    Point p3(3, 4);
    
    cout << "Point p1: " << p1 << endl;
    cout << "Point p2: " << p2 << endl;
    cout << "Point p3: " << p3 << endl;
    
    // Addition
    Point sum = p1 + p2;
    cout << "p1 + p2 = " << sum << endl;
    
    // Subtraction
    Point diff = p1 - p2;
    cout << "p1 - p2 = " << diff << endl;
    
    // Equality comparison
    cout << "p1 == p2: " << (p1 == p2 ? "true" : "false") << endl;
    cout << "p1 == p3: " << (p1 == p3 ? "true" : "false") << endl;
    
    // Increment operators
    cout << "\nIncrement Operations:" << endl;
    cout << "Before increment - p1: " << p1 << endl;
    
    Point p4 = p1++;  // postfix
    cout << "After p1++ - p1: " << p1 << ", returned: " << p4 << endl;
    
    Point p5 = ++p1;  // prefix
    cout << "After ++p1 - p1: " << p1 << ", returned: " << p5 << endl;
    
    cout << "\n=== Demo Complete ===" << endl;
    
    return 0;
}
