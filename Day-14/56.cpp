#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[10];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];}
    cout << "Duplicate elements in the array are: ";
    bool foundDuplicate = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                foundDuplicate = true;
                break;}}}

    if (!foundDuplicate) {
        cout << "None";
    }
    cout << endl;
    return 0;
}