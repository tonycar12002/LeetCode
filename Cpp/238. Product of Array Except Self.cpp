/*
Author: Tony Hsiao
Date: 2021/04/21
Topic: 238. Product of Array Except Self
Speed: 20 ms, 25 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int total = 1;
    int zero_nums = 0;
    for (const auto& num : nums) {
      if (num != 0)
        total *= num;
      else
        zero_nums++;
    }
    std::vector<int> ans;
    for (const auto& num : nums) {
      if (num != 0 && zero_nums != 0) {
        ans.push_back(0);
      } else if (num != 0){
        ans.push_back(total / num);
      } else if (num == 0 && zero_nums >= 2) {
        ans.push_back(0);
      } else if (num == 0 && zero_nums == 1) {
        ans.push_back(total);
      }
    }
    return ans;
  } // end function
};