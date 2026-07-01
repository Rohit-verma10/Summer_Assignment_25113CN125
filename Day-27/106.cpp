#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
class Employee {
private:
    int id;
    string name;
    string designation;
    double salary;

public:

    Employee(int empId, string empName, string empDesig, double empSalary) {
        id = empId;
        name = empName;
        designation = empDesig;
        salary = empSalary;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getDesignation() const { return designation; }
    double getSalary() const { return salary; }

    void setName(string newName) { name = newName; }
    void setDesignation(string newDesig) { designation = newDesig; }
    void setSalary(double newSalary) { salary = newSalary; }

    void displayRecord() const {
        cout << left << setw(10) << id 
             << setw(25) << name 
             << setw(20) << designation 
             << "$" << fixed << setprecision(2) << salary << endl;
    }
};
void addEmployee(vector<Employee>& db);
void displayAllEmployees(const vector<Employee>& db);
void searchEmployee(const vector<Employee>& db);
void updateEmployee(vector<Employee>& db);
void deleteEmployee(vector<Employee>& db);
void showMenu();

int main() {
    vector<Employee> employeeDB;
    int choice;
    do {
        showMenu();
        cout << "Enter your choice (1-6): ";
        while (!(cin >> choice)) { // Input validation
            cout << "Invalid input. Please enter a number between 1 and 6: ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        switch (choice) {
            case 1:
                addEmployee(employeeDB);
                break;
            case 2:
                displayAllEmployees(employeeDB);
                break;
            case 3:
                searchEmployee(employeeDB);
                break;
            case 4:
                updateEmployee(employeeDB);
                break;
            case 5:
                deleteEmployee(employeeDB);
                break;
            case 6:
                cout << "\nExiting the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void showMenu() {
    cout << "\n=========================================\n";
    cout << "       EMPLOYEE MANAGEMENT SYSTEM        \n";
    cout << "=========================================\n";
    cout << "1. Add New Employee\n";
    cout << "2. Display All Employees\n";
    cout << "3. Search Employee by ID\n";
    cout << "4. Update Employee Record\n";
    cout << "5. Delete Employee Record\n";
    cout << "6. Exit\n";
    cout << "-----------------------------------------\n";
}

void addEmployee(vector<Employee>& db) {
    int id;
    string name, designation;
    double salary;

    cout << "\n--- Add New Employee ---\n";
    cout << "Enter Employee ID: ";
    cin >> id;

    for (const auto& emp : db) {
        if (emp.getId() == id) {
            cout << "Error: Employee with ID " << id << " already exists!\n";
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Designation: ";
    getline(cin, designation);
    cout << "Enter Salary: ";
    cin >> salary;
    db.push_back(Employee(id, name, designation, salary));
    cout << "Employee record added successfully!\n";
}

void displayAllEmployees(const vector<Employee>& db) {
    if (db.empty()) {
        cout << "\nNo employee records found.\n";
        return;
    }
    cout << "\n-------------------------------------------------------------------\n";
    cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Designation" << "Salary" << endl;
    cout << "-------------------------------------------------------------------\n";
    for (const auto& emp : db) {
        emp.displayRecord();
    }
    cout << "-------------------------------------------------------------------\n";
}

void searchEmployee(const vector<Employee>& db) {
    if (db.empty()) {
        cout << "\nDatabase is empty.\n";
        return;
    }
    int id;
    cout << "\nEnter Employee ID to search: ";
    cin >> id;

    for (const auto& emp : db) {
        if (emp.getId() == id) {
            cout << "\nRecord Found:\n";
            cout << "-------------------------------------------------------------------\n";
            emp.displayRecord();
            cout << "-------------------------------------------------------------------\n";
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}
void updateEmployee(vector<Employee>& db) {
    if (db.empty()) {
        cout << "\nDatabase is empty.\n";
        return;
    }
    int id;
    cout << "\nEnter Employee ID to update: ";
    cin >> id;

    for (auto& emp : db) {
        if (emp.getId() == id) {
            string name, designation;
            double salary;

            cin.ignore();
            cout << "Enter New Name (Current: " << emp.getName() << "): ";
            getline(cin, name);
            cout << "Enter New Designation (Current: " << emp.getDesignation() << "): ";
            getline(cin, designation);
            cout << "Enter New Salary (Current: $" << emp.getSalary() << "): ";
            cin >> salary;

            emp.setName(name);
            emp.setDesignation(designation);
            emp.setSalary(salary);

            cout << "Record updated successfully!\n";
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

void deleteEmployee(vector<Employee>& db) {
    if (db.empty()) {
        cout << "\nDatabase is empty.\n";
        return;
    }
    int id;
    cout << "\nEnter Employee ID to delete: ";
    cin >> id;

    for (auto it = db.begin(); it != db.end(); ++it) {
        if (it->getId() == id) {
            db.erase(it);
            cout << "Employee record deleted successfully!\n";
            return;
    }}
    cout << "Employee with ID " << id << " not found.\n";
}