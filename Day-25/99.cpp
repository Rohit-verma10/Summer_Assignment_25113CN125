#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int count;
    std::cout << "How many names do you want to sort? ";
    if (!(std::cin >> count) || count <= 0) {
        std::cout << "Invalid number of names.\n";
        return 1;
    }
    std::cin.ignore();
    std::vector<std::string> names;
    std::cout << "Enter " << count << " names (one per line):\n";
    for (int i = 0; i < count; ++i) {
        std::string temp_name;
        std::cout << "Name " << (i + 1) << ": ";
        std::getline(std::cin, temp_name);
        names.push_back(temp_name);
    }
    std::sort(names.begin(), names.end());
    std::cout << "\nNames in alphabetical order:\n";
    for (const auto& name : names) {
        std::cout << name << "\n";
    }
    return 0;
}