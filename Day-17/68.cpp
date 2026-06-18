#include<iostream>
#include<vector>
#include<unordered_set>
std::vector<int> findcommonelements(const std::vector<int>& vec1,const std::vector<int>& vec2) {
    std::unordered_set<int>elementsset(vec1.begin(),vec1.end());
    std::unordered_set<int>resultset;
    for (int num : vec2) {
        if (elementsset.count(num)>0) {
            resultset.insert(num);}}
    return std::vector<int>(resultset.begin(),resultset.end());
}
int main() {
    std::vector<int>list1={4, 9, 5, 4, 1, 7};
    std::vector<int>list2={9, 4, 9, 8, 4, 2};
    std::vector<int>common=findcommonelements(list1, list2);
    std::cout<<"Common elements: ";
    for (int num:common) {
        std::cout << num << " ";
    }
    std::cout<<std::endl;
    return 0;
}