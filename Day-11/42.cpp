#include <iostream>
using namespace std;
int findmax(int num1,int num2) {
    if (num1>num2) {
        return num1;
    } else {
        return num2;}}
int main() {
    int a,b;
    cout<<"Enter the value of a:";
    cin>>a;
    cout<<"Enter the value of b:";
    cin>>b;
    int maximum=findmax(a,b);
    cout<<"The maximum value is:"<<maximum<<endl;
    return 0;
}