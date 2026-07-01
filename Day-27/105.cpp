#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    int age;
    string course;
    double cgpa;
public:
    Student(int roll, string studentName, int studentAge, string studentCourse, double studentCgpa) {
        rollNumber = roll;
        name = studentName;
        age = studentAge;
        course = studentCourse;
        cgpa = studentCgpa;
    }
    int getRollNumber() const { return rollNumber; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getCourse() const { return course; }
    double getCGPA() const { return cgpa; }

    void setName(string newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void setCourse(string newCourse) { course = newCourse; }
    void setCGPA(double newCgpa) { cgpa = newCgpa; }
    void displayRow() const {
        cout << left << setw(12) << rollNumber 
             << setw(25) << name 
             << setw(8) << age 
             << setw(15) << course 
             << setw(6) << fixed << setprecision(2) << cgpa << endl;
    }};
class StudentManagementSystem {
private:
    vector<Student> students;
    int findStudentIndex(int rollNumber) {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].getRollNumber() == rollNumber) {
                return i; 
            } }
        return -1; 
    }

public:
    void addStudent() {
        int roll, age;
        string name, course;
        double cgpa;

        cout << "\n--- Add New Student Record ---\n";
        cout << "Enter Roll Number: ";
        cin >> roll;

        if (findStudentIndex(roll) != -1) {
            cout << "Error: Student with Roll Number " << roll << " already exists!\n";
            return;
        }

        cin.ignore(); 
        cout << "Enter Full Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Course/Major: ";
        getline(cin, course);
        cout << "Enter CGPA: ";
        cin >> cgpa;

        students.push_back(Student(roll, name, age, course, cgpa));
        cout << "Success: Student record added successfully!\n";
    }

    void viewAllStudents() const {
        if (students.empty()) {
            cout << "\nDatabase is empty. No student records found.\n";
            return;
        }

        cout << "\n" << string(66, '=') << "\n";
        cout << left << setw(12) << "Roll No" 
             << setw(25) << "Name" 
             << setw(8) << "Age" 
             << setw(15) << "Course" 
             << setw(6) << "CGPA" << endl;
        cout << string(66, '=') << "\n";

        for (const auto& student : students) {
            student.displayRow();
        }
        cout << string(66, '=') << "\n";
    }

    void searchStudent() {
        if (students.empty()) {
            cout << "\nDatabase is empty.\n";
            return;
        }

        int roll;
        cout << "\nEnter Roll Number to search: ";
        cin >> roll;

        int index = findStudentIndex(roll);
        if (index != -1) {
            cout << "\nRecord Found:\n";
            cout << "-----------------------\n";
            cout << "Roll Number : " << students[index].getRollNumber() << "\n";
            cout << "Name        : " << students[index].getName() << "\n";
            cout << "Age         : " << students[index].getAge() << "\n";
            cout << "Course      : " << students[index].getCourse() << "\n";
            cout << "CGPA        : " << students[index].getCGPA() << "\n";
            cout << "-----------------------\n";
        } else {
            cout << "Error: Student record not found.\n";
        }
    }
    void updateStudent() {
        if (students.empty()) {
            cout << "\nDatabase is empty.\n";
            return;
        }
        int roll;
        cout << "\nEnter Roll Number to update: ";
        cin >> roll;
        int index = findStudentIndex(roll);
        if (index == -1) {
            cout << "Error: Student record not found.\n";
            return;
        }
        int choice;
        cout << "\nRecord found! What do you want to update?\n";
        cout << "1. Name\n2. Age\n3. Course\n4. CGPA\n5. Update All Fields\nEnter Choice (1-5): ";
        cin >> choice;
        cin.ignore(); 
        if (choice == 1 || choice == 5) {
            string newName;
            cout << "Enter New Name: ";
            getline(cin, newName);
            students[index].setName(newName);
        }
        if (choice == 2 || choice == 5) {
            int newAge;
            cout << "Enter New Age: ";
            cin >> newAge;
            students[index].setAge(newAge);
        }
        if (choice == 3 || choice == 5) {
            string newCourse;
            cin.ignore();
            cout << "Enter New Course: ";
            getline(cin, newCourse);
            students[index].setCourse(newCourse);
        }
        if (choice == 4 || choice == 5) {
            double newCgpa;
            cout << "Enter New CGPA: ";
            cin >> newCgpa;
            students[index].setCGPA(newCgpa);
        }
        
        cout << "Success: Student record updated successfully!\n";
    }

    void deleteStudent() {
        if (students.empty()) {
            cout << "\nDatabase is empty.\n";
            return;
        }

        int roll;
        cout << "\nEnter Roll Number to delete: ";
        cin >> roll;

        int index = findStudentIndex(roll);
        if (index != -1) {
            students.erase(students.begin() + index);
            cout << "Success: Student record deleted successfully!\n";
        } else {
            cout << "Error: Student record not found.\n";
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "  STUDENT RECORD MANAGEMENT SYSTEM  \n";
        cout << "====================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. View All Student Records\n";
        cout << "3. Search Student Record\n";
        cout << "4. Update Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit Application\n";
        cout << "------------------------------------\n";
        cout << "Enter your selection (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: sms.addStudent(); break;
            case 2: sms.viewAllStudents(); break;
            case 3: sms.searchStudent(); break;
            case 4: sms.updateStudent(); break;
            case 5: sms.deleteStudent(); break;
            case 6: cout << "\nExiting program. Goodbye!\n"; break;
            default: cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}