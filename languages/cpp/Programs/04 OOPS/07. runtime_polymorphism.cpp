#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cmath>
using namespace std;

// Base class with virtual functions
class Shape {
protected:
    string name;
    string color;
    
public:
    Shape(string n, string c) : name(n), color(c) {}
    
    // Virtual functions - enable polymorphism
    virtual double area() const {
        cout << "Base Shape area calculation" << endl;
        return 0.0;
    }
    
    virtual double perimeter() const {
        cout << "Base Shape perimeter calculation" << endl;
        return 0.0;
    }
    
    virtual void display() const {
        cout << "Shape: " << name << " (Color: " << color << ")" << endl;
    }
    
    virtual void draw() const {
        cout << "Drawing a generic shape" << endl;
    }
    
    // Non-virtual function
    string getName() const { return name; }
    string getColor() const { return color; }
    
    // Virtual destructor - crucial for proper cleanup
    virtual ~Shape() {
        cout << "Shape destructor called for " << name << endl;
    }
};

// Derived class 1: Circle
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(string color, double r) : Shape("Circle", color), radius(r) {}
    
    // Override virtual functions
    double area() const override {
        cout << "Circle area calculation: π × r²" << endl;
        return 3.14159 * radius * radius;
    }
    
    double perimeter() const override {
        cout << "Circle perimeter calculation: 2 × π × r" << endl;
        return 2 * 3.14159 * radius;
    }
    
    void display() const override {
        cout << "Circle (Color: " << color << ", Radius: " << radius << ")" << endl;
    }
    
    void draw() const override {
        cout << "Drawing a " << color << " circle with radius " << radius << endl;
    }
    
    // Circle-specific method
    double getDiameter() const {
        return 2 * radius;
    }
    
    ~Circle() {
        cout << "Circle destructor called" << endl;
    }
};

// Derived class 2: Rectangle
class Rectangle : public Shape {
private:
    double length, width;
    
public:
    Rectangle(string color, double l, double w) 
        : Shape("Rectangle", color), length(l), width(w) {}
    
    // Override virtual functions
    double area() const override {
        cout << "Rectangle area calculation: length × width" << endl;
        return length * width;
    }
    
    double perimeter() const override {
        cout << "Rectangle perimeter calculation: 2 × (length + width)" << endl;
        return 2 * (length + width);
    }
    
    void display() const override {
        cout << "Rectangle (Color: " << color << ", " << length << "×" << width << ")" << endl;
    }
    
    void draw() const override {
        cout << "Drawing a " << color << " rectangle " << length << "×" << width << endl;
    }
    
    // Rectangle-specific methods
    bool isSquare() const {
        return length == width;
    }
    
    ~Rectangle() {
        cout << "Rectangle destructor called" << endl;
    }
};

// Derived class 3: Triangle
class Triangle : public Shape {
private:
    double side1, side2, side3;
    
public:
    Triangle(string color, double s1, double s2, double s3) 
        : Shape("Triangle", color), side1(s1), side2(s2), side3(s3) {}
    
    // Override virtual functions
    double area() const override {
        cout << "Triangle area calculation using Heron's formula" << endl;
        double s = (side1 + side2 + side3) / 2;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    
    double perimeter() const override {
        cout << "Triangle perimeter calculation: sum of all sides" << endl;
        return side1 + side2 + side3;
    }
    
    void display() const override {
        cout << "Triangle (Color: " << color << ", Sides: " 
             << side1 << ", " << side2 << ", " << side3 << ")" << endl;
    }
    
    void draw() const override {
        cout << "Drawing a " << color << " triangle with sides " 
             << side1 << ", " << side2 << ", " << side3 << endl;
    }
    
    // Triangle-specific method
    string getTriangleType() const {
        if (side1 == side2 && side2 == side3) return "Equilateral";
        if (side1 == side2 || side2 == side3 || side1 == side3) return "Isosceles";
        return "Scalene";
    }
    
    ~Triangle() {
        cout << "Triangle destructor called" << endl;
    }
};

// Function that demonstrates polymorphism
void analyzeShape(const Shape& shape) {
    cout << "\n--- Shape Analysis ---" << endl;
    shape.display();
    shape.draw();
    cout << "Area: " << shape.area() << endl;
    cout << "Perimeter: " << shape.perimeter() << endl;
    cout << "----------------------" << endl;
}

// Function that works with Shape pointers
void processShape(Shape* shape) {
    if (shape) {
        cout << "\nProcessing: " << shape->getName() << endl;
        cout << "Area: " << shape->area() << endl;
        cout << "Perimeter: " << shape->perimeter() << endl;
    }
}

int main() {
    cout << "=== RUNTIME POLYMORPHISM DEMO ===" << endl;
    cout << "=================================\n" << endl;
    
    // Create objects
    Circle circle("Red", 5.0);
    Rectangle rectangle("Blue", 8.0, 6.0);
    Triangle triangle("Green", 3.0, 4.0, 5.0);
    
    cout << "--- Direct Object Calls ---" << endl;
    circle.display();
    rectangle.display();
    triangle.display();
    
    cout << "\n--- Polymorphic Function Calls ---" << endl;
    // Pass objects to polymorphic function
    analyzeShape(circle);     // Calls Circle's overridden methods
    analyzeShape(rectangle);  // Calls Rectangle's overridden methods
    analyzeShape(triangle);   // Calls Triangle's overridden methods
    
    cout << "\n--- Polymorphic Container Demo ---" << endl;
    
    // Store different shapes in same container using base class pointers
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>("Yellow", 3.0));
    shapes.push_back(make_unique<Rectangle>("Purple", 5.0, 4.0));
    shapes.push_back(make_unique<Triangle>("Orange", 6.0, 8.0, 10.0));
    shapes.push_back(make_unique<Circle>("Pink", 7.0));
    
    double totalArea = 0.0;
    double totalPerimeter = 0.0;
    
    cout << "\nAll shapes in container:" << endl;
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "\n" << (i + 1) << ". ";
        shapes[i]->display();
        shapes[i]->draw();
        
        double area = shapes[i]->area();        // Polymorphic call
        double perimeter = shapes[i]->perimeter(); // Polymorphic call
        
        totalArea += area;
        totalPerimeter += perimeter;
        
        cout << "   Area: " << area << endl;
        cout << "   Perimeter: " << perimeter << endl;
    }
    
    cout << "\n--- Summary ---" << endl;
    cout << "Total shapes: " << shapes.size() << endl;
    cout << "Total area: " << totalArea << endl;
    cout << "Total perimeter: " << totalPerimeter << endl;
    cout << "Average area: " << totalArea / shapes.size() << endl;
    
    cout << "\n--- Polymorphic Pointer Demo ---" << endl;
    
    // Base class pointer pointing to derived objects
    Shape* shapePtr;
    
    Circle c2("Cyan", 4.0);
    shapePtr = &c2;
    cout << "\nShape pointer pointing to Circle:" << endl;
    processShape(shapePtr);
    
    Rectangle r2("Magenta", 6.0, 3.0);
    shapePtr = &r2;
    cout << "\nShape pointer pointing to Rectangle:" << endl;
    processShape(shapePtr);
    
    cout << "\n--- Virtual Destructor Demo ---" << endl;
    cout << "Creating and destroying shapes through base pointer:" << endl;
    
    Shape* dynamicShape = new Circle("Lime", 2.5);
    delete dynamicShape;  // Virtual destructor ensures proper cleanup
    
    cout << "\n=== Demo Complete ===" << endl;
    
    return 0;
}
