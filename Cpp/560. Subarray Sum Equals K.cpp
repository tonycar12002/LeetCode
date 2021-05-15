/*
Author: Tony Hsiao
Date: 2021/05/15
Topic: 560. Subarray Sum Equals K
Speed: 80 ms, 42 MB
Note:
 nums[0] + .... + nums[j] = sum(1 to i) - k;
 nums[j + 1] + .... + nums[i] =  k;
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
  int subarraySum(vector<int>& nums, int k) {
    std::unordered_map<int, int> record = {{0, 1}};
    int sum = 0, ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      ans += record[sum - k];
      record[sum]++;
    }
    return ans;
  }
};