#include <iostream>
using namespace std;
int main() {
    int rows=5;
    for (int i=1; i<=rows; i++) {
        for (int j=1; j<=rows-i; j++) {
            cout<<" ";
        }
        char ch='A';
        for (int j=1; j<=i; j++) {
            cout<<ch++;
        }
        ch-=2;
        for (int j=1; j<i;j++) {
            cout<<ch--;
        }
        cout<<endl;
    }
    return 0;
}