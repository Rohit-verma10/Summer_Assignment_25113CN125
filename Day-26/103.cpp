#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class ATMSimulator {
private:
    string accountHolder;
    int accountNumber;
    int pinCode;
    double accountBalance;

public:
    ATMSimulator(string name, int accNum, int pin, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        pinCode = pin;
        accountBalance = initialBalance;
    }
    bool authenticate(int enteredPin) {
        return enteredPin == pinCode;
    }
    void deposit(double amount) {
        if (amount > 0) {
            accountBalance += amount;
            cout << "\n[SUCCESS] $" << fixed << setprecision(2) << amount 
                 << " deposited successfully.\n";
        } else {
            cout << "\n[ERROR] Invalid deposit amount.\n";
        }
    }
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "\n[ERROR] Invalid withdrawal amount.\n";
        } else if (amount > accountBalance) {
            cout << "\n[ERROR] Insufficient funds! Current balance: $" 
                 << fixed << setprecision(2) << accountBalance << "\n";
        } else {
            accountBalance -= amount;
            cout << "\n[SUCCESS] Please collect your cash.\nWithdrawn: $" 
                 << fixed << setprecision(2) << amount << "\n";
        }
    }
    void displayBalance() {
        cout << "\n--- Account Information ---" << endl;
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << accountBalance << endl;
        cout << "---------------------------\n";
    }
};
int main() {
    ATMSimulator userAccount("Jane Doe", 987654321, 1234, 1500.75);
    int enteredPin;
    int maxAttempts = 3;
    bool isAuthenticated = false;
    cout << "========================================" << endl;
    cout << "     WELCOME TO THE VIRTUAL ATM SYSTEM  " << endl;
    cout << "========================================" << endl;

    while (maxAttempts > 0) {
        cout << "\nPlease enter your 4-digit PIN: ";
        if (!(cin >> enteredPin)) {
            cout << "[ERROR] Invalid input. Please enter numbers only.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (userAccount.authenticate(enteredPin)) {
            isAuthenticated = true;
            break;
        } else {
            maxAttempts--;
            cout << "[ERROR] Incorrect PIN. Attempts remaining: " << maxAttempts << "\n";
        }
    }
    if (!isAuthenticated) {
        cout << "\n[BLOCKED] Too many incorrect attempts. Your card is temporarily locked.\n";
        return 0;
    }
    int choice;
    double amount;
    do {
        cout << "\n========== ATM MENU ==========" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit / Logout" << endl;
        cout << "==============================" << endl;
        cout << "Select an option (1-4): ";
    
        if (!(cin >> choice)) {
            cout << "[ERROR] Invalid selection. Enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        switch (choice) {
            case 1:
                userAccount.displayBalance();
                break;

            case 2:
                cout << "Enter the amount to deposit: $";
                cin >> amount;
                userAccount.deposit(amount);
                break;

            case 3:
                cout << "Enter the amount to withdraw: $";
                cin >> amount;
                userAccount.withdraw(amount);
                break;

            case 4:
                cout << "\nThank you for using our ATM services. Goodbye!\n";
                break;

            default:
                cout << "\n[ERROR] Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}