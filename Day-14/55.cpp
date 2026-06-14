#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if (n < 2) {
        cout << "Array must have at least two elements." << endl;
        return 0;
    }
    int arr[10];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {

            second_largest = largest;
            largest = arr[i];
        } 
        else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    if (second_largest == INT_MIN) {
        cout << "There is no unique second largest element (all elements might be equal)." << endl;
    } else {
        cout << "The second largest element is: " << second_largest << endl;
    }
    return 0;
}