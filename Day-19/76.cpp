#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the square matrix (N x N): ";
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n));
    cout<<"Enter the elements of the matrix:\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>matrix[i][j];
        }}
    int principalsum=0;
    int secondarysum=0;

    for (int i=0;i<n;i++) {
        principalsum+=matrix[i][i];     
        secondarysum+=matrix[i][n-i-1]; 
    }
    cout<<"\nSum of Principal Diagonal: "<<principalsum<<endl;
    cout<<"Sum of Secondary Diagonal: "<<secondarysum<<endl;
    int totaldiagonalsum=principalsum+secondarysum;
    if (n%2!= 0) {
        totaldiagonalsum-=matrix[n/2][n/2];
    }
    cout<<"Total Diagonal Sum (overlapping element counted once): "<<totaldiagonalsum<<endl;
    return 0;
}