#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(const std::string& str1,const std::string&str2) {

    if (str1.length()!=str2.length()){
        return false;
    }
    std::vector<int>charCount(256,0);
    for (size_t i=0;i<str1.length();i++) {
        charCount[str1[i]]++; 
        charCount[str2[i]]--; 
    }
    for (int count:charCount) {
        if (count!=0) {
            return false;}}
    return true;
}
int main(){
    std::string string1,string2;

    std::cout<<"Enter the first string: ";
    std::cin>>string1;
    std::cout<<"Enter the second string: ";
    std::cin>>string2;
    if (isAnagram(string1,string2)) {
        std::cout<<"\""<<string1<<"\"and \""<<string2<<"\"are anagrams."<<std::endl;
    } else {
        std::cout<<"\""<<string1<<"\"and \""<<string2<<"\"are NOT anagrams."<<std::endl;
    }
    return 0;
}