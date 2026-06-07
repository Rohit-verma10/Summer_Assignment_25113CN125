#include<iostream>
using namespace std;
int main ()
{
    int num, sum = 0;
    cout<<"Enter an integer=";
    cin >> num;
    cout<<"\nThe number is="<< num; 
 
    while(num!=0){
        sum += num % 10;
        num = num / 10;
    }
    cout <<"\nSum of digits: " << sum;
    return 0;
}