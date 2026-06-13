#include <iostream>
#include <cmath>
using namespace std;
bool isPerfect(int num) {
    if (num <= 1) {
        return false;
    }
    int sum = 1;
    int sqrtNum = std::sqrt(num);
    for (int i = 2; i <= sqrtNum; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }}}
    return sum == num;
}
int main() {
    int number;
    std::cout << "Enter a positive integer: ";
    std::cin >> number;
    if (isPerfect(number)) {
        std::cout << number << " is a perfect number.\n";
    } else {
        std::cout << number << " is NOT a perfect number.\n";
    }
    return 0;}