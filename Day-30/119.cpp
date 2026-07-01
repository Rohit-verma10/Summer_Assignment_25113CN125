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
    Employee(int empId, string empName, string empDesignation, double empSalary) {
        id = empId;
        name = empName;
        designation = empDesignation;
        salary = empSalary;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getDesignation() const { return designation; }
    double getSalary() const { return salary; }

    void setName(string empName) { name = empName; }
    void setDesignation(string empDesignation) { designation = empDesignation; }
    void setSalary(double empSalary) { salary = empSalary; }

    void displayRecord() const {
        cout << left << setw(10) << id 
             << setw(25) << name 
             << setw(20) << designation 
             << "$" << fixed << setprecision(2) << salary << endl;
    }
};

class ManagementSystem {
private:
    vector<Employee> employees;

    int findEmployeeIndex(int id) {
        for (size_t i = 0; i < employees.size(); ++i) {
            if (employees[i].getId() == id) {
                return i;
            }
        }
        return -1; 
    }

public:
    void addEmployee() {
        int id;
        string name, designation;
        double salary;

        cout << "\n--- Add New Employee ---\n";
        cout << "Enter Employee ID: ";
        cin >> id;

        if (findEmployeeIndex(id) != -1) {
            cout << "\nError: Employee ID " << id << " already exists!\n";
            return;
        }

        cin.ignore(); 
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Salary: ";
        cin >> salary;

        employees.push_back(Employee(id, name, designation, salary));
        cout << "\nEmployee added successfully!\n";
    }

    void viewAllEmployees() {
        if (employees.empty()) {
            cout << "\nNo employee records found.\n";
            return;
        }

        cout << "\n-------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Designation" << "Salary" << endl;
        cout << "-------------------------------------------------------------\n";
        for (const auto& emp : employees) {
            emp.displayRecord();
        }
        cout << "-------------------------------------------------------------\n";
    }
    void searchEmployee() {
        if (employees.empty()) {
            cout << "\nNo employee records found.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to Search: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index != -1) {
            cout << "\nRecord Found:\n";
            cout << "-------------------------------------------------------------\n";
            cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Designation" << "Salary" << endl;
            cout << "-------------------------------------------------------------\n";
            employees[index].displayRecord();
            cout << "-------------------------------------------------------------\n";
        } else {
            cout << "\nEmployee with ID " << id << " not found.\n";
        }
    }
    void updateEmployee() {
        if (employees.empty()) {
            cout << "\nNo employee records found.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to Update: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index != -1) {
            string newName, newDesignation;
            double newSalary;

            cin.ignore();
            cout << "Enter New Name (Current: " << employees[index].getName() << "): ";
            getline(cin, newName);
            cout << "Enter New Designation (Current: " << employees[index].getDesignation() << "): ";
            getline(cin, newDesignation);
            cout << "Enter New Salary (Current: $" << employees[index].getSalary() << "): ";
            cin >> newSalary;

            employees[index].setName(newName);
            employees[index].setDesignation(newDesignation);
            employees[index].setSalary(newSalary);

            cout << "\nEmployee record updated successfully!\n";
        } else {
            cout << "\nEmployee with ID " << id << " not found.\n";
        }
    }

    void deleteEmployee() {
        if (employees.empty()) {
            cout << "\nNo employee records found.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to Delete: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index != -1) {
            employees.erase(employees.begin() + index);
            cout << "\nEmployee record deleted successfully!\n";
        } else {
            cout << "\nEmployee with ID " << id << " not found.\n";
        }
    }
};

int main() {
    ManagementSystem system;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "       EMPLOYEE MANAGEMENT SYSTEM        \n";
        cout << "=========================================\n";
        cout << "1. Add Employee\n";
        cout << "2. View All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Delete Employee\n";
        cout << "6. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "\nInvalid input! Please enter a number between 1 and 6.\n";
            continue;
        }

        switch (choice) {
            case 1: system.addEmployee(); break;
            case 2: system.viewAllEmployees(); break;
            case 3: system.searchEmployee(); break;
            case 4: system.updateEmployee(); break;
            case 5: system.deleteEmployee(); break;
            case 6: cout << "\nExiting system. Goodbye!\n"; break;
            default: cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}