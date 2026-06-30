#include<iostream>
#include<string>

char getmaxoccurringchar(const std::string& str) {
    int freq[256]={0};
    
    for (char ch:str) {
        freq[static_cast<unsigned char>(ch)]++;
    }
    int maxcount=-1;
    char maxchar=' ';
    
    for (char ch:str){
        unsigned char uCh=static_cast<unsigned char>(ch);
        if (freq[uCh]>maxcount) {
            maxcount=freq[uCh];
            maxchar=ch;
} }
    return maxchar;
}
int main(){
    std::string inputStr;
    std::cout<<"Enter a string: ";
    std::getline(std::cin,inputStr);
    if (inputStr.empty()){
        std::cout<<"The string is empty."<<std::endl;
        return 0;
    }
    char result=getmaxoccurringchar(inputStr);
    std::cout<<"The maximum occurring character is: '"<<result<<"'"<<std::endl;
    return 0;
}