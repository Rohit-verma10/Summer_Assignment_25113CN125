#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
 
    getline(cin, sentence);

   stringstream ss(sentence);
    string word;
    string longestWord = "";

    while (ss >> word) {

        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
    if (longestWord.empty()) {
        cout << "No words were found." << endl;
    } else {
        cout << "The longest word is: " << longestWord << endl;
        cout << "Its length is: " << longestWord.length() << " characters." << endl;
    }
    return 0;
}