#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
std::vector<int>getintersection(const std::vector<int>& arr1,const std::vector<int>& arr2) {
    std::unordered_set<int>set1(arr1.begin(),arr1.end());
    std::vector<int>result;
    for (int num:arr2) {
        if (set1.count(num)) {
            result.push_back(num);
            set1.erase(num);}}
    return result;}
int main(){
    std::vector<int>arr1={4, 9, 5, 4};
    std::vector<int>arr2={9, 4, 9, 8, 4};
    std::vector<int> intersection = getintersection(arr1, arr2);
    std::cout<<"Intersection: ";
    for (int num:intersection) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    return 0;
}