#include <iostream>

using namespace std;

class BankAccount {
private:
    static int accountCount; // Static member to keep track of the number of accounts
    static double bankMoney; // Static member to keep track of total money in the bank
    int accountNumber;
    double balance;
public:
    BankAccount(double balance): balance(balance) { // Default constructor initializes accountNumber and balance
        accountCount++;
        bankMoney += balance; // Update the static bankMoney with the current balance
        accountNumber = accountCount; // Assign a unique account number
    }
    static int getAccountCount() {
        return accountCount; // Static method to access the static member
    }
    static double getBankMoney() {
        return bankMoney; // Static method to access the static member
    }

    int getAccountNumber() const {
        return accountNumber; // Non-static method to access the instance member
    }
    double getBalance() const {
        return balance; // Non-static method to access the instance member
    }
};

int BankAccount::accountCount = 0; // Initialize static member
double BankAccount::bankMoney = 0.0; // Initialize static member

int main() {
    BankAccount account1(1000);
    BankAccount account2(2000);
    BankAccount account3(3000);   
    cout << "Total accounts created: " << BankAccount::getAccountCount() << endl;
    cout << "Account 1 number: " << account1.getAccountNumber() << endl;
    cout << "Account 2 number: " << account2.getAccountNumber() << endl;
    cout << "Account 3 number: " << account3.getAccountNumber() << endl;
    cout << "Account 1 balance: " << account1.getBalance() << endl;
    cout << "Account 2 balance: " << account2.getBalance() << endl;
    cout << "Account 3 balance: " << account3.getBalance() << endl;
    
    cout << "Total money in bank: " << BankAccount::getBankMoney() << endl;
    
    return 0;
}