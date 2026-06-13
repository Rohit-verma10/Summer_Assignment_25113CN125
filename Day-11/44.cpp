#include <iostream>
unsigned long long getfactorialiterative(int n) {
    if (n<0) {
        return 0;
    }
    unsigned long long result=1;
    for (int i=1;i<=n;++i) {
        result*=i;
    }
    return result;
}
int main() {
    int number;
    std::cout<<"Enter a positive integer: ";
    std::cin>>number;
    if (number<0) {
        std::cout<<"Error: Factorial of a negative number does not exist"<<std::endl;
    } else {
        std::cout<<"Factorial of "<<number<<" is "<<getfactorialiterative(number)<<std::endl;
    }
    return 0;
}