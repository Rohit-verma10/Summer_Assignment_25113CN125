#include <iostream>
#include <string>
using namespace std;
std::string compressString(const std::string& str) {
    if (str.empty()) {
        return "";
    }
    std::string compressed = "";
    int n = str.length();
    for (int i = 0; i < n; i++) {
    
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++; 
        }
        compressed += str[i];
        compressed += std::to_string(count);
    }


    return compressed.length() < str.length() ? compressed : str;
}

int main() {
    std::string input1 = "AAABBCDDDD";
    std::string input2 = "ABC"; 
    std::cout << "Original: " << input1 << " -> Compressed: " << compressString(input1) << std::endl;
    std::cout << "Original: " << input2 << " -> Compressed: " << compressString(input2) << std::endl;
    return 0;
}