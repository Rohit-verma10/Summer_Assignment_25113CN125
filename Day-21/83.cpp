#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    std::string text;
    int vowels=0;
    int consonants=0;
    std::cout<<"Enter a line of text: ";
    std::getline(std::cin,text);
    for (char ch:text){
    
        if (std::isalpha(ch)){
            char lowerCh=std::tolower(ch);
            if (lowerCh=='a'||lowerCh=='e'||lowerCh=='i'||lowerCh=='o'||lowerCh=='u'){
                vowels++;
            } 
            else {
                consonants++;
            }}}
    std::cout<<"Total Vowels: "<<vowels<<std::endl;
    std::cout<<"Total Consonants: "<<consonants<<std::endl;
    return 0;
}