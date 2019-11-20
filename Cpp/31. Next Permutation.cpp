/*
Author: Tony Hsiao
Date: 2019/11/20
Topic: 31. Next Permutation
Speed: 8 ms, 8.6 MB
Note: Find the regular of ascend series, from end to start
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int length = nums.size();
        if (length == 0 || length == 1)
            return void();
        for (int i=length-1; i>=1; --i) {
            if (nums[i-1] < nums[i]) {
                int index;
                for (index=length-1; index>=i; --index) {
                    if (nums[index] > nums[i-1])
                        break;
                }
                std::swap(nums[i-1], nums[index]);
                std::sort(nums.begin() + i, nums.end());
                break;
            }
            if (i == 1)
                std::sort(nums.begin(), nums.end());
        }
    }
};