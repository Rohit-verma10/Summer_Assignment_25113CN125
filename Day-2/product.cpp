#include<iostream>
using namespace std;
int main()
{
    int n,product=1;
    cout<<"enter the number = ";
    cin>>n;
    while(n!=0)
    {
        product*=n%10;
        n/=10;
    }
    cout<<"product of digits of entered number is = " <<product<< endl;
    return 0;
}
