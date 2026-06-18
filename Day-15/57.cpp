#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;
    cout<<"Enter the number of elements in the array: ";
    cin>>size;
    if (size<=0) {
        cout<<"Invalid array size!"<<endl;
        return 1;
    }
    vector<int>arr(size);
    cout<<"Enter "<<size<<" integers:"<< endl;
    for (int i = 0; i < size; i++) {
        cout<<"Element " << i + 1 << ": ";
        cin>>arr[i];
    }
    cout<<"\nOriginal Array: ";
    for (int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int start=0;
    int end=size-1;

    while (start<end) {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        start++;
        end--;
    }
    cout<<"Reversed Array: ";
    for (int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}