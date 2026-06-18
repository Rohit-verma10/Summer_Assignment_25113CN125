#include<iostream>
#include<vector>
#include<set>
std::vector<int>findunion(const std::vector<int>& arr1,const std::vector<int>& arr2) {
    std::set<int>uniqueelements;
    for (int num:arr1) {
        uniqueelements.insert(num);
    }
    for (int num:arr2){
        uniqueelements.insert(num);
    }
    std::vector<int>unionresult(uniqueelements.begin(),uniqueelements.end());
    return unionresult;
}
int main() {
    std::vector<int>array1={1, 3, 2, 4, 3, 5};
    std::vector<int>array2={2, 4, 6, 5, 5, 7};
    std::vector<int>result=findunion(array1,array2);
    std::cout<<"union of the two arrays: ";
    for (int num:result) {
        std::cout<<num<< " ";
    }
    std::cout<<std::endl;
    return 0;
}