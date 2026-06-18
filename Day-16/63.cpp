#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n,targetSum;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter "<<n<<" integers: ";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the target sum: ";
    cin>>targetSum;
    cout<<"\nPairs that sum to "<<targetSum<<":"<<endl;
    bool found =false;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++) {
            if (arr[i]+arr[j]==targetSum) {
                cout<<"[ "<<arr[i]<<", "<<arr[j]<<" ]"<<endl;
                found = true;
            }}}
    if (!found) {
        cout<<"No valid pairs found"<<endl;
    }
    return 0;
}