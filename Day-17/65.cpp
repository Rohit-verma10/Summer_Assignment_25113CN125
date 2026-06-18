#include<iostream>
using namespace std;
int main(){
    int arr1[]={10,20,30};
    int arr2[]={40,50,60,70};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    int sizemerged=size1+size2;
    int merged[sizemerged];
    int k=0;
    for (int i=0;i<size1;i++) {
        merged[k++]=arr1[i];
    }
    for (int i=0;i<size2;i++) {
        merged[k++]=arr2[i];
    }
    cout<<"merged Array: ";
    for (int i=0;i<sizemerged;i++) {
        cout<<merged[i]<<" ";
    }
    cout<<endl;
    return 0;
}