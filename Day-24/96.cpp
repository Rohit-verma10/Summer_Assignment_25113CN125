#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
std::string removeDuplicates(const std::string& str) {
    std::unordered_set<char> seen;
    std::string result = "";

    for (char ch : str) {

        if (seen.find(ch) == seen.end()) {
            result.push_back(ch); 
            seen.insert(ch);
    } }
    return result;
}
int main() {
    std::string inputStr;
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputStr); 
    std::string cleanStr = removeDuplicates(inputStr);
    std::cout << "String after removing duplicates: " << cleanStr << std::endl;
    return 0;
}