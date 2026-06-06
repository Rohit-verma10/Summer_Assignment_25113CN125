#include <iostream>
double calculatePower(double x, long long n) {

    if (n == 0) {
        return 1.0;
    }
    
    if (n < 0) {
        x = 1.0 / x;
        n = -n; 
    }
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    
    return result;
}

int main() {
    double base;
    long long exponent;
    
    std::cout << "Enter base (x): ";
    std::cin >> base;
    std::cout << "Enter exponent (n): ";
    std::cin >> exponent;
    double answer = calculatePower(base, exponent);
    std::cout << base << "^" << exponent << " = " << answer << std::endl;
    return 0;
}