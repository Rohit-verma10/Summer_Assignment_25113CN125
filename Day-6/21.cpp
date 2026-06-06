#include <bitset>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int decimalNum;
    cout << "Enter a positive decimal integer: ";
    cin >> decimalNum;


      const int sz = ceil(log2(10));
    bitset<5> binaryRepresentation(decimalNum);

    cout << "Binary representation: " << endl;

    return 0;
}