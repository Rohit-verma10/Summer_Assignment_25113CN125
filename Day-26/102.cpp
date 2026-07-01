#include <iostream>
using namespace std;

int main() {
    int age;
    const int VOTING_AGE = 18;
    cout << "Enter your age to check voting eligibility: ";
    cin >> age;
    if (age >= VOTING_AGE) {
        cout << "Congratulations! You are eligible to vote." << endl;
        cout << "Please ensure you are registered to participate in the elections." << endl;
    } else {
        int years_left = VOTING_AGE - age;
        cout << "Sorry, you are not eligible to vote yet." << endl;
        cout << "You will be eligible to vote in " << years_left << " year(s)." << endl;
    }
    return 0;
}