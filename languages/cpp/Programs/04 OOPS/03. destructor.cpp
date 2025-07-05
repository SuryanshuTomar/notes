#include <iostream>

using namespace std;

class BankAccount {
public:
    string accountHolder;
    double* balance;
    int accountNumber;

    // Constructor to initialize the attributes
    BankAccount(string holder, double initialBalance, int accNumber) 
        : accountHolder(holder), accountNumber(accNumber) {
        balance = new double(); // Dynamically allocate memory for balance
        (*this->balance) = initialBalance; // Initialize balance
        cout << "Constructor called! Account created for " << accountHolder << endl;
    }   
    // Destructor to clean up dynamically allocated memory
    ~BankAccount() {
        delete balance;
        cout << "Destructor called! Account for " << accountHolder << " closed." << endl;
    }       
};

int main() {
    // Creating an object of BankAccount class using the constructor
    BankAccount account1("Alice Smith", 1000.0, 123456);
    cout << "Account Holder: " << account1.accountHolder << endl;
    cout << "Account Number: " << account1.accountNumber << endl;
    cout << "Balance: $" << *account1.balance << endl;

    // The destructor will be called automatically when the object goes out of scope
    return 0;
}
