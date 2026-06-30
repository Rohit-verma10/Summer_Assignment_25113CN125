#include<iostream>
using namespace std;
int main(){
    int rows,cols;
    cout<<"Enter rows and columns of the matrix: ";
    cin>>rows>>cols;
    int matrix[100][100];
    int transpose[100][100];
    cout<<"\nEnter elements of the matrix:\n";
    for (int i=0;i<rows;++i) {
        for (int j=0;j<cols;++j) {
            cout<<"Enter element at [" << i << "][" << j << "]: ";
            cin>>matrix[i][j];
    }}
    cout<<"\nOriginal Matrix:\n";
    for (int i=0;i<rows;++i) {
        for (int j=0;j<cols;++j) {
            cout<<matrix[i][j]<< " ";
        }
        cout<<"\n";
    }
    for (int i=0;i<rows;++i) {
        for (int j=0;j<cols;++j) {
            transpose[j][i]=matrix[i][j];
        }}
    cout <<"\nTransposed Matrix:\n";
    for (int i=0;i<cols;++i) {
        for (int j=0;j<rows;++j) {
            cout<<transpose[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}