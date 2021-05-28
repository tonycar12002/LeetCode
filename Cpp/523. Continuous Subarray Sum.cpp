/*
Author: Tony Hsiao
Date: 2021/05/26
Topic: 523. Continuous Subarray Sum
Speed: 152 ms, 96.6 MB
Note: 利用余数的封闭性处理 https://blog.csdn.net/myRealization/article/details/108754006
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
  bool checkSubarraySum(vector<int>& nums, int k) {
    if (k < 0)
      k = -k;
    if (k == 0) {
      for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] == nums[i + 1])
          return true;
      }
      return false;
    }
    std::unordered_map<int, int> mod_table;
    mod_table[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      int mod = sum % k;
      if (mod_table.find(mod) == mod_table.end())
        mod_table[mod] = i;
      // avoid zero
      else if (i - mod_table[mod] > 1)
        return true;
    }
    return false;
  }
};
