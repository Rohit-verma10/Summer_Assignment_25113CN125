#include<iostream>
#include<string>
using namespace std;
int main(){
    std::string text;
    std::cout<<"Enter a lowercase string: ";
    std::getline(std::cin,text);
    
    for (size_t i=0;i<text.length();++i) {
        if (text[i]>='a'&&text[i]<='z') {
            text[i]=text[i]-32; }
    }
    std::cout<<"Uppercase string: "<<text<<std::endl;
    return 0;
}