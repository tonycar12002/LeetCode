/*
Author: Tony Hsiao
Date: 2019/11/21
Topic: 136. Single Number
Speed:  ms,  MB
Note: 
1. 暴力直接sort
2. XOR 運算 (屌)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i=0; i<nums.size(); ++i)
      ans ^= nums[i];
    return ans;
  }
};