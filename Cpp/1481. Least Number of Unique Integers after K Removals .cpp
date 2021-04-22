/*
Author: Tony Hsiao
Date: 2021/03/28
Topic: 1481. Least Number of Unique Integers after K Removals
Speed: 160 ms, 62.6 MB
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
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    std::unordered_map<int, int> value;
    for (const auto& v : arr)
      value[v]++;
    std::vector<int> nums;
    for (const auto& [key, times] : value)
      nums.push_back(times);
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > k)
        return nums.size() - i;
      k -= nums[i];
    }
    return 0;
  }
};