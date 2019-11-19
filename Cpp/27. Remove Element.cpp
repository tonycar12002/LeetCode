/*
Author: Tony Hsiao
Date: 2019/11/19
Topic: 27. Remove Element
Speed: 4 ms, 8.7 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != val) {
                swap(nums[i], nums[index]);
                index += 1;
            }
        }
        return index;
    }
};