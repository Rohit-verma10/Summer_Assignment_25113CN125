#include <iostream>
using namespace std;
int addtwonumbers(int num1,int num2) {
    return num1+num2;
}
int main() {
    int a,b,sum;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    sum=addtwonumbers(a,b);
    cout<<"The sum of"<<a<<"and"<<b<<"is:"<<sum<<endl;
    return 0;
}