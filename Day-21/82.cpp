#include<iostream>
#include<string>
using namespace std;
int main(){
    std::string str="Open ai";

    int start=0;
    int end=str.length()-1;
    while(start<end){
        char temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
    std::cout<<"Reversed string: "<<str<<std::endl;
    return 0;
}