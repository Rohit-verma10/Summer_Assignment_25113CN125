#include<iostream>
#include<string>
using namespace std;

string removeSpaces(string& s){
    int n=s.length();
    for (int i=0;i<n;i++) {
        if (s[i]==' ') {

            for (int j=i;j<n-1;j++){
                s[j]=s[j+1];
            }
            n--;    
            i--;   
        }}
    return s.substr(0, n);
}
int main(){
    string s="G L Bajaj Institute Of Technology And Management ";
    cout<<removeSpaces(s);
    return 0;
}