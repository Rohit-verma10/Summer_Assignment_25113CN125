#include <iostream>
#include <string>
#include <vector>
using namespace std;
void findCommonTwoStrings(const string& str1, const string& str2) {
    vector<bool> presentInStr1(26, false);
    vector<bool> presentInStr2(26, false);
    for (char ch : str1) {
        presentInStr1[ch - 'a'] = true;
    }
    for (char ch : str2) {
        presentInStr2[ch - 'a'] = true;
    }
    cout << "Common characters: ";
    bool found = false;
    for (int i = 0; i < 26; i++) {
        if (presentInStr1[i] && presentInStr2[i]) {
            cout << (char)(i + 'a') << " ";
            found = true;
        } }
    if (!found) {
        cout << "No common characters found.";
    }
    cout << endl;
}
int main() {
    string s1 = "portfolio";
    string s2 = "courses";
    findCommonTwoStrings(s1, s2);
    return 0;
}