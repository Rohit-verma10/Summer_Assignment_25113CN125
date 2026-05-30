#include<iostream>
using namespace std;
int main()
{
    int n,count=0;
    cout<<"enter the digits of number= ";
    cin>> n;
    if(n==0){
    count=1;}
    else{
    while(n>0)
    {
        n=n/10;
        count++;
    }}
    cout<<"number of digits="<<count<<endl;
    return 0;
}