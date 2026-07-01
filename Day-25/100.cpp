#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    std::vector<std::string> words = {"bajaj", "institute", "GL"};
    std::cout << "Original words:\n";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << "\n\n";
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
      
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() < b.length();
    });
    std::cout << "Words sorted by length (ascending):\n";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << "\n";
    return 0;
}