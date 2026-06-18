#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void reversesubarray(vector<int>& arr, int start, int end) {
    while (start<end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void rightrotate(vector<int>& arr,int d) {
    int n=arr.size();
    d=d%n; 
    
    if (d==0) return;
    //reversesubarray(arr,0,d-1);
    //reversesubarray(arr,d,n-1);
    //reversesubarray(arr,0,n-1);
    reversesubarray(arr, n - d, n - 1);
    reversesubarray(arr, 0, n - d - 1);
    reversesubarray(arr, 0, n - 1);

}
int main() {
    int n,d;
    cout<<"Enter the number of elements in the array: ";
    if (!(cin>>n)||n<=0) {
        cout<<"Invalid array size."<<endl;
        return 1;
    }
    vector<int>arr(n);
    cout<<"Enter "<<n<<" integers:"<<endl;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of positions to right rotate: ";
    cin>>d;
    
    if (d<0) {
        cout<<"Rotation count cannot be negative."<<endl;
        return 1;
    }
    rightrotate(arr, d);
    cout<<"Array after right rotation: "<<endl;
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}