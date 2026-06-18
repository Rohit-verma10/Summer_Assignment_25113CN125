#include <iostream>
#include <vector>
using namespace std;
void moveZeroesToEnd(vector<int>& arr) {
    int count = 0; 
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }}
    while (count < n) {
        arr[count++] = 0;
    }}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    moveZeroesToEnd(arr);
    cout << "Array after moving zeroes to the end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}