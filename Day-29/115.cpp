#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void displayMenu();
void checkLength();
void reverseString();
void concatenateStrings();
void convertToUppercase();
void convertToLowercase();

int main() {
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice (1-6): ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        
        std::cin.ignore(10000, '\n'); 

        switch (choice) {
            case 1:
                checkLength();
                break;
            case 2:
                reverseString();
                break;
            case 3:
                concatenateStrings();
                break;
            case 4:
                convertToUppercase();
                break;
            case 5:
                convertToLowercase();
                break;
            case 6:
                std::cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please choose between 1 and 6.\n";
        }
        std::cout << "\n-----------------------------------\n";
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    std::cout << "\n=== STRING OPERATIONS SYSTEM ===\n";
    std::cout << "1. Find Length of a String\n";
    std::cout << "2. Reverse a String\n";
    std::cout << "3. Concatenate Two Strings\n";
    std::cout << "4. Convert to Uppercase\n";
    std::cout << "5. Convert to Lowercase\n";
    std::cout << "6. Exit\n";
}

void checkLength() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    std::cout << "Length of the string is: " << str.length() << " characters.\n";
}

void reverseString() {
    std::string str;
    std::cout << "Enter a string to reverse: ";
    std::getline(std::cin, str);
    
    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    
    std::cout << "Reversed string: " << reversedStr << "\n";
}

void concatenateStrings() {
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);
    
    std::cout << "Concatenated result: " << str1 + str2 << "\n";
}

void convertToUppercase() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    
    std::string upperStr = str;
    std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    
    std::cout << "Uppercase string: " << upperStr << "\n";
}

void convertToLowercase() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    
    std::cout << "Lowercase string: " << lowerStr << "\n";
}