#include <iostream>
using namespace std;

int getfactorial(int digit) {
    int fact = 1;
    for (int i = 1; i <= digit; i++) {
        fact *= i;
    }
    return fact;
}
int main() {
    int originalnum, num, lastdigit;
    int factorialSum = 0;

    cout << "Enter a positive integer to check: ";
    cin >> originalnum;
    num = originalnum;

    while (num > 0) {
        lastdigit = num % 10;
        
        factorialSum += getfactorial(lastdigit);
        num /= 10;
    }
    if (factorialSum == originalnum) {
        cout << originalnum << " is a Strong Number." << endl;
    } else {
        cout << originalnum << " is NOT a Strong Number." << endl;
    }

    return 0;
}