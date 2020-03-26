/*
Author: Tony Hsiao
Date: 2020/03/26
Topic: 41. First Missing Positive
Speed: 0 ms, 6.6 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
          return 1;
        int counts[len];
        memset(counts, 0, sizeof(counts));
        for (int i=0; i<len; ++i) {
          if (nums[i] > 0 && nums[i]-1 < len)
            counts[nums[i]-1] = 1;
        }      
        for (int i=0; i<len; ++i) {
          if (counts[i] == 0)
            return i+1;
        }
        return len + 1;
    }
};


