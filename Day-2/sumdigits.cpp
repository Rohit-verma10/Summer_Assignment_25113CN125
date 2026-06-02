#include<iostream>
using namespace std;
int main()
{
    int n,sum=0;
    cout<<"enter the number = ";
    cin>>n;
    while(n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    cout<<"sum of digits of entered number is = " <<sum<< endl;
    return 0;
}
