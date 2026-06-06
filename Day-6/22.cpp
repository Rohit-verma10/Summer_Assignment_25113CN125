#include <iostream>
#include <string>
using namespace std;

int main(){
    string num;
    cout << "Enter a binary number: ";
    cin >> num;
     int dec_value = 0;
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    cout<<dec_value<<endl;
}