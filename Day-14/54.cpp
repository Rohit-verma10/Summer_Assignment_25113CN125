#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
  int n;
cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[10];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> frequencyMap;
    for (int i = 0; i < n; i++) {
        frequencyMap[arr[i]]++;
    }
    cout << "Frequency of elements in the array is: "
         << endl;
    for (auto& i : frequencyMap) {
        cout << i.first << " -> " << i.second << endl;
    }
    return 0;
}