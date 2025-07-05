#include <iostream>
#include <vector>

using namespace std;

struct Circle {
    private:
        float radius;

        float circumference() const
        {
            return 2 * 3.14159 * radius; // Using an approximation for PI
        }

        float area() const
        {
            return 3.14159 * radius * radius; // Using an approximation for PI
        }

        friend struct CircleInfo;

    public:
        Circle(float r) : radius(r) {}
};

struct CircleInfo {
    public:
        void displayCircleInfo(const Circle &circle)
        {
            cout << "------------------------" << endl;
            cout << "Circle Information:" << endl;
            cout << "Circle with radius: " << circle.radius << endl;
            cout << "Circumference: " << circle.circumference() << endl;
            cout << "Area: " << circle.area() << endl;
            cout << "------------------------" << endl;
            cout << endl;
        }
};

int main() {
    vector<Circle> circles = { {3.0}, {4.5}, {5.0} };

    CircleInfo circleInfo;
    for (const auto &circle : circles) {
        circleInfo.displayCircleInfo(circle);
    }

    return 0;
}