#include <iostream>
using namespace std;
void printfibonacciiterative(int terms) {
    if (terms <= 0) {
        std::cout<<"Please enter a number greater than 0"<<std::endl;
        return;
    }
    long long first = 0,second = 1,next;
    std::cout << "Fibonacci Series (Iterative): ";
    for (int i = 0; i < terms; ++i) {
        if (i == 0) {
            std::cout << first;
            continue;
        }
        if (i == 1) {
            std::cout << ", " << second;
            continue;}
        next = first+ second;
        first = second;
        second = next;
        std::cout << ", " << next;
    }
    std::cout <<std::endl;
}
long long getfibonaccirecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return getfibonaccirecursive(n- 1) + getfibonaccirecursive(n - 2);
}
int main() {
    int numberOfTerms;
    std::cout<< "Enter the number of terms to generate: ";
    std::cin >> numberOfTerms;
    printfibonacciiterative(numberOfTerms);

    if (numberOfTerms > 0) {
        std::cout << "Fibonacci Series (Recursive): ";
        for (int i = 0; i < numberOfTerms; ++i) {
            std::cout << getfibonaccirecursive(i);
            if (i < numberOfTerms - 1) {
                std::cout << ", ";
            } }
        std::cout << std::endl; }
    return 0;
}