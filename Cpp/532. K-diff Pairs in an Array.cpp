/*
Author: Tony Hsiao
Date: 2021/05/23
Topic: 532. K-diff Pairs in an Array
Speed: 59.38 ms, 41.69 MB
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
  int findPairs(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    std::map<std::pair<int, int>, int> pair_exist;
    std::deque<int> q;
    int ans = 0;
    for (const auto& num : nums) {
      auto it = q.begin();
      while (!q.empty() && it != q.end()) {
        if (num - *it == k) {
          if (pair_exist.find({*it, num}) != pair_exist.end()) {
            q.pop_front();
            it = q.begin();
          } else {
            pair_exist[{*it, num}] = 1;
            ans++;
            it++;
          }
        } else if (num - q.front() > k) {
          q.pop_front();
          it = q.begin();
        } else {
          break;
        }
      }
      q.emplace_back(num);
    }
    return ans;
  }
};
