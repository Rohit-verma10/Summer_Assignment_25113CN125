#include <iostream>
#include <vector>

std::vector<int> removeDuplicates(const std::vector<int>& nums) {
    std::vector<int> uniqueVals;
    for (int i = 0; i < nums.size(); ++i) {
        bool isUnique = true;
        for (int j = 0; j < uniqueVals.size(); ++j) {
            if (nums[i] == uniqueVals[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueVals.push_back(nums[i]);
        }
    }
    return uniqueVals;
}
int main() {
    std::vector<int> nums = {2, 3, 1, 1, 4, 3, -2, 1};
    std::vector<int> result = removeDuplicates(nums);
    for (int val : result) {
        std::cout << val << " ";
    }
    return 0;
}