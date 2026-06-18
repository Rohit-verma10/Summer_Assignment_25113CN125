#include<iostream>
#include<vector>
using namespace std;
int findmissingnumber(const vector<int>& arr,int n) {
    int expectedSum=(n*(n+1))/2;
    int actualSum=0;
    for (int num:arr) {
        actualSum+=num;
    }
    return expectedSum-actualSum;
}
int main() {
    int n;
    cout<<"Enter the total number of elements expected (N): ";
    cin>>n;
    if (n<=1) {
        cout<<"N must be greater than 1 to have a missing number"<<endl;
        return 0;
    }
    vector<int>arr(n-1);
    cout<<"Enter "<<n-1<<" distinct elements ranging from 1 to "<<n<<":"<<endl;
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    int missingNumber=findmissingnumber(arr,n);
    cout<<"\nThe missing number is: "<<missingNumber<<endl;
    return 0;
}