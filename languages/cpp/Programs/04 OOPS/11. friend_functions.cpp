#include <iostream>
#include <vector>

using namespace std;

struct EquilateralTriangle {
    private: 
        float sidelength;
        
        float circumference() const {
            return 3 * sidelength;
        }

        float area() const {
            return (sidelength * sidelength * 1.73205) / 4; // Using sqrt(3) approximation
        }   
        
        friend void displayTriangleInfo(const EquilateralTriangle& triangle);

    public:
        EquilateralTriangle(float length) : sidelength(length) {}

};

void displayTriangleInfo(const EquilateralTriangle& triangle) {
    cout << "------------------------" << endl;
    cout << "Equilateral Triangle Information:" << endl;
    cout << "Equilateral Triangle with side length: " << triangle.sidelength << endl;
    cout << "Circumference: " << triangle.circumference() << endl;
    cout << "Area: " << triangle.area() << endl;
    cout << "------------------------" << endl;
    cout << endl;
}

int main() {
    vector<EquilateralTriangle> triangles = { {3.0}, {4.5}, {5.0} };

    for (const auto& triangle : triangles) {
        displayTriangleInfo(triangle);
    }

    return 0;
}