#include<iostream>
#include<vector>
using namespace std;

vector<int>sumcols(vector<vector<int>> &mat) {
    int m=mat.size(),n=mat[0].size();
    vector<int>result;

    for(int i=0;i<m;i++) {
        int sum=0;
        for(int j=0;j<n;j++) {
            sum+=mat[i][j];
        }
        result.push_back(sum);
    }
    for(int j=0;j<n;j++) {
        int sum=0;
        for(int i=0;i<m;i++) {
            sum+=mat[i][j];
        }
        result.push_back(sum);
    }

    return result;
}

void printArray(vector<int> &arr, int m, int n) {
    for(int j=0;j<n;j++) {
        cout<<"Sum of column "<<j<<" = "<<arr[m+j]<<endl;
    }
}
int main(){
    vector<vector<int>>mat={
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    vector<int> result=sumcols(mat);
    printArray(result,4,4);
    return 0;
}