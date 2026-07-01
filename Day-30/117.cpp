#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

string names[MAX_STUDENTS];
int rollNumbers[MAX_STUDENTS];
double gpas[MAX_STUDENTS];

int studentCount = 0;

void displayMenu();
void addStudent();
void viewAllStudents();
void searchStudent();
void updateStudent();

int main() {
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewAllStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                cout << "\nExiting Student Record System. Goodbye!\n";
                return 0;
            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 5.\n";
        }
    }
    return 0;
}

void displayMenu() {
    cout << "\n===================================";
    cout << "\n      STUDENT RECORD SYSTEM        ";
    cout << "\n===================================";
    cout << "\n1. Add New Student";
    cout << "\n2. View All Students";
    cout << "\n3. Search Student by Roll Number";
    cout << "\n4. Update Student Record";
    cout << "\n5. Exit";
    cout << "\n===================================\n";
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "\nError: System database is full!\n";
        return;
    }

    cout << "\n--- Add New Student ---\n";
    
    cout << "Enter Student Full Name: ";
    getline(cin, names[studentCount]);

    cout << "Enter Roll Number: ";
    cin >> rollNumbers[studentCount];

    for (int i = 0; i < studentCount; i++) {
        if (rollNumbers[i] == rollNumbers[studentCount]) {
            cout << "Error: A student with this roll number already exists!\n";
            return;
        }
    }

    cout << "Enter GPA: ";
    cin >> gpas[studentCount];

    studentCount++;
    cout << "\nStudent record added successfully!\n";
}

void viewAllStudents() {
    if (studentCount == 0) {
        cout << "\nNo records found. The database is empty!\n";
        return;
    }

    cout << "\n--------------------------------------------------\n";
    cout << "Roll No\t\tName\t\t\tGPA\n";
    cout << "--------------------------------------------------\n";
    for (int i = 0; i < studentCount; i++) {
        cout << rollNumbers[i] << "\t\t" << names[i] << "\t\t" << gpas[i] << "\n";
    }
    cout << "--------------------------------------------------\n";
}
void searchStudent() {
    if (studentCount == 0) {
        cout << "\nNo records found to search through!\n";
        return;
    }

    int searchRoll;
    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    for (int i = 0; i < studentCount; i++) {
        if (rollNumbers[i] == searchRoll) {
            cout << "\nStudent Found:";
            cout << "\n-------------------------";
            cout << "\nRoll Number : " << rollNumbers[i];
            cout << "\nName        : " << names[i];
            cout << "\nGPA         : " << gpas[i];
            cout << "\n-------------------------\n";
            return;
        }
    }
    cout << "\nStudent with Roll Number " << searchRoll << " not found.\n";
}

void updateStudent() {
    if (studentCount == 0) {
        cout << "\nNo records found to update!\n";
        return;
    }

    int searchRoll;
    cout << "\nEnter Roll Number to update: ";
    cin >> searchRoll;

    for (int i = 0; i < studentCount; i++) {
        if (rollNumbers[i] == searchRoll) {
            cout << "\nCurrent Details:\nName: " << names[i] << " | GPA: " << gpas[i] << "\n\n";
            cin.ignore(); 

            cout << "Enter New Name: ";
            getline(cin, names[i]);

            cout << "Enter New GPA: ";
            cin >> gpas[i];

            cout << "\nRecord updated successfully!\n";
            return;
        }
    }
    cout << "\nStudent with Roll Number " << searchRoll << " not found.\n";
}