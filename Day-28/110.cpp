#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class BankAccount {
private:
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
   
    BankAccount(int accNum, std::string name, double initialDeposit) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = initialDeposit;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "\n[Success] Deposit of $" << amount << " successful!";
        } else {
            std::cout << "\n[Error] Invalid deposit amount.";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "\n[Error] Invalid withdrawal amount.";
        } else if (amount > balance) {
            std::cout << "\n[Error] Insufficient balance! Current Balance: $" << balance;
        } else {
            balance -= amount;
            std::cout << "\n[Success] Withdrawal of $" << amount << " successful!";
        }
    }

    void displayAccountDetails() const {
        std::cout << "\n----------------------------";
        std::cout << "\nAccount Number : " << accountNumber;
        std::cout << "\nAccount Holder : " << accountHolderName;
        std::cout << "\nTotal Balance  : $" << std::fixed << std::setprecision(2) << balance;
        std::cout << "\n----------------------------\n";
    }
};

BankAccount* findAccount(std::vector<BankAccount>& accounts, int accNum) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNum) {
            return &accounts[i];
        }
    }
    return nullptr;
}

int main() {
    std::vector<BankAccount> accounts;
    int choice;
    int nextAccountNumber = 1001;
    do {
        std::cout << "\n======= BANK MANAGEMENT SYSTEM =======";
        std::cout << "\n1. Create New Account";
        std::cout << "\n2. Deposit Funds";
        std::cout << "\n3. Withdraw Funds";
        std::cout << "\n4. Check Account Details";
        std::cout << "\n5. Exit System";
        std::cout << "\nEnter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                double initialDeposit;
                
                std::cout << "\nEnter account holder's full name: ";
                std::cin.ignore(); 
                std::getline(std::cin, name);
                
                std::cout << "Enter initial deposit amount: $";
                std::cin >> initialDeposit;

                if (initialDeposit < 0) {
                    std::cout << "\n[Error] Initial deposit cannot be negative!\n";
                } else {
                    BankAccount newAcc(nextAccountNumber, name, initialDeposit);
                    accounts.push_back(newAcc);
                    std::cout << "\n[Success] Account successfully created!";
                    std::cout << "\nYour Assigned Account Number is: " << nextAccountNumber << "\n";
                    nextAccountNumber++;
                }
                break;
            }
            case 2: {
                int accNum;
                double amount;
                std::cout << "\nEnter account number: ";
                std::cin >> accNum;

                BankAccount* acc = findAccount(accounts, accNum);
                if (acc != nullptr) {
                    std::cout << "Enter deposit amount: $";
                    std::cin >> amount;
                    acc->deposit(amount);
                } else {
                    std::cout << "\n[Error] Account number not found.";
                }
                break;
            }
            case 3: {
                int accNum;
                double amount;
                std::cout << "\nEnter account number: ";
                std::cin >> accNum;

                BankAccount* acc = findAccount(accounts, accNum);
                if (acc != nullptr) {
                    std::cout << "Enter withdrawal amount: $";
                    std::cin >> amount;
                    acc->withdraw(amount);
                } else {
                    std::cout << "\n[Error] Account number not found.";
                }
                break;
            }
            case 4: {
                int accNum;
                std::cout << "\nEnter account number: ";
                std::cin >> accNum;

                BankAccount* acc = findAccount(accounts, accNum);
                if (acc != nullptr) {
                    acc->displayAccountDetails();
                } else {
                    std::cout << "\n[Error] Account number not found.";
                }
                break;
            }
            case 5:
                std::cout << "\nThank you for utilizing our Bank Management System. Goodbye!\n";
                break;
                
            default:
                std::cout << "\n[Error] Invalid choice menu option. Please try again.";
        }
    } while (choice != 5);

    return 0;
}