#include <iostream>
#include <vector>
using namespace std;
std::vector<int> mergesortedarrays(const int arr1[], int size1, const int arr2[], int size2) {
    std::vector<int> mergedresult;
    mergedresult.reserve(size1 + size2); 
    int i = 0;
    int j = 0; 
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            mergedresult.push_back(arr1[i]);
            i++;
        } else {
            mergedresult.push_back(arr2[j]);
            j++;
        }}
    while (i < size1) {
        mergedresult.push_back(arr1[i]);
        i++;
    }
    while (j < size2) {
        mergedresult.push_back(arr2[j]);
        j++;
    }
    return mergedresult;
}
int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::vector<int> mergedarray = mergesortedarrays(arr1, size1, arr2, size2);
    std::cout << "Merged Sorted Array: ";
    for (int num : mergedarray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}