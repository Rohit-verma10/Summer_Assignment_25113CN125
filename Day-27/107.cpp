#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
class Employee {
private:
    int id;
    std::string name;
    std::string designation;
    double basicSalary;
 
    double hra; 
    double da;  
    
  
    double tax;
    double pf; 

public:
  
    Employee(int empId, std::string empName, std::string empDesig, double salary)
        : id(empId), name(empName), designation(empDesig), basicSalary(salary) {
        calculateSalaryComponents();
    }
    void calculateSalaryComponents() {
        hra = basicSalary * 0.20; 
        da = basicSalary * 0.10; 
        pf = basicSalary * 0.12; 
        
        double grossSalary = basicSalary + hra + da;
        
  
        if (grossSalary * 12 > 1000000) {
            tax = grossSalary * 0.15; 
        } else if (grossSalary * 12 > 500000) {
            tax = grossSalary * 0.05;
        } else {
            tax = 0.0;
        }
    }
    int getId() const { return id; }
    std::string getName() const { return name; }
    
    double getGrossSalary() const {
        return basicSalary + hra + da;
    }

    double getNetSalary() const {
        return getGrossSalary() - (pf + tax);
    }
    void displayPayslip() const {
        std::cout << "\n=============================================\n";
        std::cout << "              SALARY PAYSLIP                 \n";
        std::cout << "=============================================\n";
        std::cout << std::left << std::setw(15) << "Emp ID:" << id << "\n";
        std::cout << std::left << std::setw(15) << "Name:" << name << "\n";
        std::cout << std::left << std::setw(15) << "Designation:" << designation << "\n";
        std::cout << "---------------------------------------------\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::left << std::setw(25) << "(+) Basic Salary:" << basicSalary << "\n";
        std::cout << std::left << std::setw(25) << "(+) HRA Allowance:" << hra << "\n";
        std::cout << std::left << std::setw(25) << "(+) DA Allowance:" << da << "\n";
        std::cout << "------------- Deductions --------------------\n";
        std::cout << std::left << std::setw(25) << "(-) Provident Fund:" << pf << "\n";
        std::cout << std::left << std::setw(25) << "(-) Income Tax:" << tax << "\n";
        std::cout << "---------------------------------------------\n";
        std::cout << std::left << std::setw(25) << "GROSS SALARY:" << getGrossSalary() << "\n";
        std::cout << std::left << std::setw(25) << "NET PAYABLE:" << getNetSalary() << "\n";
        std::cout << "=============================================\n\n";
    }};
class SalaryManagementSystem {
private:
    std::vector<Employee> employees;

public:

    void addEmployee() {
        int id;
        std::string name, designation;
        double salary;

        std::cout << "\nEnter Employee ID (Numeric): ";
        while (!(std::cin >> id)) {
            std::cout << "Invalid input. Enter a numeric ID: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        

        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                std::cout << "Error: Employee ID already exists!\n";
                return;
            }
        }

        std::cin.ignore();
        std::cout << "Enter Employee Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Designation: ";
        std::getline(std::cin, designation);
        std::cout << "Enter Base Monthly Salary: ";
        while (!(std::cin >> salary) || salary < 0) {
            std::cout << "Invalid salary amount. Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        employees.emplace_back(id, name, designation, salary);
        std::cout << "Employee structural ledger updated successfully!\n";
    }

    void displayAllEmployees() const {
        if (employees.empty()) {
            std::cout << "\nNo records found in the roster tracking matrix.\n";
            return;
        }

        std::cout << "\n" << std::string(75, '=') << "\n";
        std::cout << std::left << std::setw(10) << "ID" 
                  << std::setw(25) << "Name" 
                  << std::setw(20) << "Gross Salary" 
                  << std::setw(20) << "Net Salary" << "\n";
        std::cout << std::string(75, '-') << "\n";

        for (const auto& emp : employees) {
            std::cout << std::left << std::setw(10) << emp.getId()
                      << std::setw(25) << emp.getName()
                      << std::setw(20) << emp.getGrossSalary()
                      << std::setw(20) << emp.getNetSalary() << "\n";
        }
        std::cout << std::string(75, '=') << "\n\n";
    }

    void generateIndividualPayslip() const {
        if (employees.empty()) {
            std::cout << "\nDatabase ledger is empty.\n";
            return;
        }

        int searchId;
        std::cout << "\nEnter Employee ID to fetch breakdown sheet: ";
        std::cin >> searchId;

        for (const auto& emp : employees) {
            if (emp.getId() == searchId) {
                emp.displayPayslip();
                return;
            }
        }
        std::cout << "Employee ID not matching active databases.\n";
    }
};

int main() {
    SalaryManagementSystem sms;
    int choice;

    while (true) {
        std::cout << "=== SALARY RECORD ENGINE ===\n";
        std::cout << "1. Record New Employee\n";
        std::cout << "2. View Roster Summaries\n";
        std::cout << "3. Calculate & Display Detailed Payslip\n";
        std::cout << "4. Terminate Program\n";
        std::cout << "Enter your preference: ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Please input a valid selection character sequence.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: sms.addEmployee(); break;
            case 2: sms.displayAllEmployees(); break;
            case 3: sms.generateIndividualPayslip(); break;
            case 4: std::cout << "Closing financial terminal framework.\n"; return 0;
            default: std::cout << "Invalid routing vector selected. Retrying.\n\n";
        }
    }
}