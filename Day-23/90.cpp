#include <iostream>
#include <unordered_set>
using namespace std;

char findfirstrepeatingchar(const std::string& str) {
    std::unordered_set<char>seencharacters;

    for (char ch:str){
        if (seencharacters.find(ch)!=seencharacters.end()) {
            return ch;
        }
        seencharacters.insert(ch);
    }
    return '\0'; 
}
int main(){
    std::string inputStr;
    
    std::cout<<"Enter a string: ";
    std::cin>>inputStr;

    char result=findfirstrepeatingchar(inputStr);
    if (result!='\0') {
        std::cout<<"The first repeating character is: '"<<result<<"'\n";
    }else{
        std::cout<<"No repeating characters found.\n";
    }
    return 0;
}