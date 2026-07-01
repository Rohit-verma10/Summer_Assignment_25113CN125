#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class MarksheetSystem {
private:
    string studentName;
    int rollNumber;
    float subjectMarks[5];
    string subjectNames[5] = {"Mathematics", "Physics", "Chemistry", "English", "Computer Science"};
    float totalMarks;
    float percentage;
    string finalGrade;
    bool isPassed;


    void calculateResults() {
        totalMarks = 0;
        isPassed = true;

        for (int i = 0; i < 5; i++) {
            totalMarks += subjectMarks[i];
    
            if (subjectMarks[i] < 33.0) {
                isPassed = false;
            }
        }

        percentage = (totalMarks / 500.0) * 100.0;

        if (!isPassed) {
            finalGrade = "F (Fail)";
        } else if (percentage >= 90) {
            finalGrade = "A+ (Excellent)";
        } else if (percentage >= 80) {
            finalGrade = "A (Very Good)";
        } else if (percentage >= 70) {
            finalGrade = "B (Good)";
        } else if (percentage >= 60) {
            finalGrade = "C (Fair)";
        } else if (percentage >= 50) {
            finalGrade = "D (Second Division)";
        } else {
            finalGrade = "E (Pass Class)";
        }}
public:

    void inputDetails() {
        cout << "========================================\n";
        cout << "      ENTER STUDENT INFORMATION         \n";
        cout << "========================================\n";
        cout << "Enter Student Full Name: ";
        cin.ignore(); // Clear remaining newline buffer
        getline(cin, studentName);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        cout << "\nEnter Marks Obtained (Out of 100):\n";
        for (int i = 0; i < 5; i++) {
            while (true) {
                cout << " * " << subjectNames[i] << ": ";
                cin >> subjectMarks[i];

            
                if (subjectMarks[i] >= 0 && subjectMarks[i] <= 100) {
                    break; 
                }
                cout << "   Invalid entry! Marks must be between 0 and 100.\n";
            }
        }
    
        calculateResults();
    }

 
    void displayMarksheet() const {
        cout << "\n\n";
        cout << "====================================================\n";
        cout << "             ACADEMIC REPORT CARD                   \n";
        cout << "====================================================\n";
        cout << left << setw(18) << "Student Name:" << studentName << "\n";
        cout << left << setw(18) << "Roll Number:" << rollNumber << "\n";
        cout << "----------------------------------------------------\n";
        cout << left << setw(25) << "Subject Name" << "Marks Obtained / 100\n";
        cout << "----------------------------------------------------\n";
        
        for (int i = 0; i < 5; i++) {
            cout << left << setw(28) << subjectNames[i] << fixed << setprecision(2) << subjectMarks[i] << "\n";
        }
        cout << "----------------------------------------------------\n";
        cout << left << setw(28) << "TOTAL MARKS:" << totalMarks << " / 500.00\n";
        cout << left << setw(28) << "PERCENTAGE:" << fixed << setprecision(2) << percentage << "%\n";
        cout << left << setw(28) << "FINAL STATUS:" << (isPassed ? "PASSED" : "FAILED") << "\n";
        cout << left << setw(28) << "GRADE EARNED:" << finalGrade << "\n";
        cout << "====================================================\n";
    }
};

int main() {
    MarksheetSystem student;
    
    student.inputDetails();
    student.displayMarksheet();
    
    return 0;
}