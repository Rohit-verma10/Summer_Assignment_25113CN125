#include <iostream>
using namespace std;

void showMenu();
void handleCalculation(int choice);

int main() {
    int choice;

    do {
        showMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            handleCalculation(choice);
        } else if (choice == 5) {
            cout << "\nExiting the calculator. Goodbye!\n";
        } else {
            cout << "\nInvalid choice! Please select a valid option from the menu.\n";
        }

    } while (choice != 5);
    return 0;
}

void showMenu() {
    cout << "\n===============================" << endl;
    cout << "      MENU-DRIVEN CALCULATOR    " << endl;
    cout << "===============================" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Exit Program" << endl;
    cout << "===============================" << endl;
}

void handleCalculation(int choice) {
    double num1, num2;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    switch (choice) {
        case 1:
            cout << "\nResult: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;
        case 2:
            cout << "\nResult: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;
        case 3:
            cout << "\nResult: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
            break;
        case 4:
            if (num2 != 0) {
                cout << "\nResult: " << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
            } else {
                cout << "\nError: Division by zero is not allowed!" << endl;
            }
            break;
        default:
            cout << "\nAn unexpected error occurred." << endl;
    }
}