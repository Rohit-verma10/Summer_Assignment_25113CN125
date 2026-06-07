#include <iostream>
using namespace std;
int reverseNumber(int num, int rev) {
    if (num == 0) {
        return rev;
    }
    int remainder=num%10;
    rev=rev*10+remainder;
    return reverseNumber(num/10,rev);
}
int main() {
    int number;
    cout<<"Enter an integer:";
    cin>>number;
    int reversed=reverseNumber(number, 0);
    cout<<"Reversed Number:"<<reversed<<endl;
    return 0;
}