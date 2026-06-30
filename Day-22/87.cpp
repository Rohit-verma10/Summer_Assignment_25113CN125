#include<iostream>
using namespace std;
int main(){ 
    string str="GL bajaj institute of technology and management";
    char ch='t';  
    int count=0; 
    for (int i=0;i<str.length();i++) {
        if (str[i]==ch){
            count++;
        }}
    cout<<"Frequency of '"<<ch<<"'="<<count<<endl;
    return 0;
}