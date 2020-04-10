/*
Author: Tony Hsiao
Date: 2020/04/10
Topic: 198. House Robber
Speed: 0 ms, 6.3 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> value(nums.size()+1, 0);
        value[0] = 0;
        value[1] = nums[0];
        for (int i=2; i<=nums.size(); ++i) {
            value[i] = max(value[i-2] + nums[i-1], value[i-1]);
        }
        return value[nums.size()];
    }
};