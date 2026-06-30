#include<iostream>
#include<string>
using namespace std;
int main(){
    std::string str;
    std::cout<<"Enter a string: ";
    std::getline(std::cin,str);
    int length=0;
    for (char c:str) {
        length++;
    }
    std::cout<<"The length of the string is: "<<length<<std::endl;
    return 0;
}