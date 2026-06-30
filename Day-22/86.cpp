#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int countWords(const std::string& sentence) {
    std::stringstream ss(sentence); 
    std::string word;
    int count=0;
    while (ss>>word) {
        count++;
    }
    return count;
}
int main(){
    std::string sentence;
    std::cout<<"Enter a sentence: ";
    std::getline(std::cin,sentence); 
    int totalWords=countWords(sentence);
    std::cout<<"Total number of words: "<<totalWords<<std::endl;
    return 0;
}