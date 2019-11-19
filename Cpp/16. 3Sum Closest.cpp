/*
Author: Tony Hsiao
Date: 2019/11/16
Topic: 16. 3Sum Closest
Speed: 16 ms, 8.7 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findClosest(const std::vector<int>& nums, const int& index, const int& target) {
        int start = index + 1;
        int end = nums.size() - 1;
        int closest = INT_MAX;
        while (end > start) {
            int tmp_sum = nums[start] + nums[end];
            if (closest == INT_MAX || abs(tmp_sum - target) <= abs(closest - target)) {
                if (tmp_sum == target)
                    return target;
                closest = tmp_sum;
            }
            if (tmp_sum > target)
                end--;
            else
                start++;
        }
        return closest;
    }

    int threeSumClosest(std::vector<int>& nums, int target) {
        std::vector<int> copy_nums(nums);
        sort(copy_nums.begin(), copy_nums.end());
        int closest = INT_MAX;
        for (int i=0; i<copy_nums.size()-2; ++i) {
            int tmp = findClosest(copy_nums, i, target - copy_nums[i]) + copy_nums[i];
            if (closest == INT_MAX || abs(target - tmp) <= abs(closest - target)) {
                if (target == tmp)
                    return target;
                closest = tmp;
            }
        }
        return closest;
  }
};


