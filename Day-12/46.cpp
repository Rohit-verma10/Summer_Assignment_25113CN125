#include <iostream>
#include <cmath>
using namespace std;
bool isArmstrong(int num) {
    if (num < 0) {
        return false; 
    }
    int originalNum = num;
    int temp = num;
    int digits = 0;
    int sum = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    temp = originalNum;
    while (temp > 0) {
        int remainder = temp % 10;
        sum += std::round(std::pow(remainder, digits)); 
        temp /= 10;
    }
    return (sum == originalNum);
}
int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;
    if (isArmstrong(number)) {
        std::cout << number << " is an Armstrong number.\n";
    } else {
        std::cout << number << " is not an Armstrong number.\n";
    }
    return 0;
}