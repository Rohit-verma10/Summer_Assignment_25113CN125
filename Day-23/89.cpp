#include <iostream>
#include <unordered_map>
using namespace std;
char findfirstnonrepeating(const std::string& str) {
    
    std::unordered_map<char,int>charCounts;
    for (char ch:str) {
        charCounts[ch]++;
    }

    for (char ch:str) {
        if (charCounts[ch]==1){
            return ch;
        }}
    return '\0';}
int main(){
    std::string inputStr;
    
    std::cout<<"Enter a string: ";
    std::cin>>inputStr;

    char result=findfirstnonrepeating(inputStr);

    if (result !='\0'){
        std::cout<<"The first non-repeating character is: '"<<result<<"'"<<std::endl;
    }else{
        std::cout<<"All characters are repeating or the string is empty."<<std::endl;
    }
    return 0;
}