#include <iostream>

using namespace std;

struct Complex {
    private:
        // Private members to store real and imaginary parts
        double real;
        double imag;
        
    public:
        // Default constructor
        Complex() : real(0), imag(0) {}

        Complex(double real, double imag) : real(real), imag(imag) {}
        // Friend function to access private members
        friend struct ComplexNumberInfo;

        // Overloading the + operator
        Complex operator+(const Complex& other) {
            Complex result;
            result.real = this->real + other.real;
            result.imag = this->imag + other.imag;
            return result;
        }

        // Overloading the - operator
        Complex operator-(const Complex& other) {
            Complex result;
            result.real = this->real - other.real;
            result.imag = this->imag - other.imag;
            return result;
        }   
};

struct ComplexNumberInfo {
    Complex complexNumber;

    void display() {
        // Displaying the complex number in a readable format
        cout << endl;
        cout << "========================" << endl;
        cout << "Complex Number Info:" << endl;
        cout << "Complex Number: " << complexNumber.real << " + " << complexNumber.imag << "i" << endl;
    }
};

struct YoutubeChannel {
    private:
        // Struct to represent a YouTube channel
        string name;
        string ownerName;
        int subscribersCount;
        int totalViews;

    public:
        // Friend struct to access private members
        friend ostream& operator<<(ostream& COUT, const YoutubeChannel& channel);
        
        // Default constructor
        YoutubeChannel() : name(""), ownerName(""), subscribersCount(0), totalViews(0) {}

        // Parameterized constructor
        YoutubeChannel (string name, string ownerName, int subscribersCount, int totalViews)
            : name(name), ownerName(ownerName), subscribersCount(subscribersCount), totalViews(totalViews) {}
};

// Overloading the << operator for YoutubeChannel
ostream& operator<<(ostream& COUT, const YoutubeChannel& channel){
    COUT << endl;
    COUT << "---------------------------" << endl;
    COUT << "YouTube Channel Information:" << endl;
    COUT << "Channel Name: " << channel.name << endl;
    COUT << "Owner Name: " << channel.ownerName << endl;
    COUT << "Subscribers Count: " << channel.subscribersCount << endl;
    COUT << "Total Views: " << channel.totalViews << endl;
    return COUT;
}

int main() {
    // Using the Complex struct
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2; // Using overloaded + operator
    Complex c4 = c1 - c2; // Using overloaded - operator

    // Displaying the results
    ComplexNumberInfo info1, info2;
    info1.complexNumber = c3;
    info1.display();
    info2.complexNumber = c4;
    info2.display();


    // Using the YoutubeChannel struct
    YoutubeChannel techChannel {"Tech Insights", "Alice Smith", 150000, 5000000};
    YoutubeChannel styleChannel {"Style Trends", "Bob Johnson", 200000, 3000000};
    
    // Displaying the YouTube channel information
    cout << techChannel << styleChannel << endl;
}