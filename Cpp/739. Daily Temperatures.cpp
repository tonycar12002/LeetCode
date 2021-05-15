/*
Author: Tony Hsiao
Date: 2021/05/11
Topic: 739. Daily Temperatures
Speed: 144 ms, 42.7 MB
Note: for much more fast method, use stack in this web https://www.cnblogs.com/grandyang/p/8097513.html
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
/// Very slow solution
struct greater_compare {
  template<typename T, typename U>
  bool operator()(T const& lhs, U const& rhs) const {
    return rhs.first < lhs.first;
  }
};
class Solution {
public:

  vector<int> dailyTemperatures(vector<int>& temperatures) {
    std::priority_queue<
    std::pair<int, int>, std::vector<std::pair<int, int>>,
        greater_compare> q;
    std::vector<int> ans(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); ++i) {
      q.push({temperatures[i], i});
      while (!q.empty()) {
        auto value = q.top();
        q.pop();
        if (value.first < temperatures[i]) {
          ans[value.second] = i - value.second;
        } else {
          q.push(value);
          break;
        }
      }
    }
    while (!q.empty()) {
      auto value = q.top();
      q.pop();
      ans[value.second] = 0;
    }
    return ans;
  }
};
