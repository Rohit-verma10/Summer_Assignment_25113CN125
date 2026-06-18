#include<iostream>
#include<utility> 
using namespace std;
void selectionSort(int arr[],int size) {
    for (int i=0;i<size-1;i++) {
        int minIndex=i;
        for (int j=i+1;j<size;j++) {
            if (arr[j]<arr[minIndex]) {
                minIndex=j;
            }}
        if (minIndex!=i) {
            swap(arr[i],arr[minIndex]);
        }}}
void printArray(const int arr[],int size) {
    for (int i=0;i<size;i++) {
        cout<<arr[i] << " ";
    }
    cout<<"\n";
}
int main() {
    int data[]={64, 25, 12, 22, 11};
    int size=sizeof(data)/sizeof(data[0]);
    cout<<"Original array: ";
    printArray(data, size) ;
    selectionSort(data, size);
    cout<<"Sorted array:   ";
    printArray(data, size);
    return 0;
}