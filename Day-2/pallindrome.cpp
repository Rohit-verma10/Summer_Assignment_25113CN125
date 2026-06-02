#include<iostream>
using namespace std;
int main()
{
    int n,rev=0,temp;
    cout<<"enter the number = ";
    cin>>n;
    temp=n;
    while(n!=0)
    {
        rev=rev*10+n%10;
        n/=10;
    }
    if(temp==rev)
        cout<<"entered number is pallindrome" <<endl;
    else
        cout<<"entered number is not pallindrome" <<endl;
    return 0;
}