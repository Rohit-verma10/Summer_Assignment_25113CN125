#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    cout<<"========================================="<<endl;
    cout<<"Welcome to the Number Guessing Game!" << endl;
    cout<<"I have chosen a number between 1 and 100." << endl;
    cout<<"Can you guess what it is?" << endl;
    cout<<"=========================================" << endl << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;
        if (userGuess > secretNumber) {
            cout << "Too high! Try a lower number." << endl << endl;
        } 
        else if (userGuess < secretNumber) {
            cout << "Too low! Try a higher number." << endl << endl;
        } 
        else {
            cout << endl << "Congratulations! You guessed the right number!" << endl;
            cout << "It took you " << attempts << " attempts." << endl;
        }
    } while (userGuess != secretNumber);

    return 0;
}