/*
Author: Tony Hsiao
Date: 2021/05/06
Topic: 57. Insert Interval
Speed: 16 ms, 17.5 MB
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
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int cur = 0;
    int start = newInterval[0], end = newInterval[1];
    for (auto interval : intervals) {
      if (interval[1] < newInterval[0]) {
        ans.push_back(interval);
        cur++;
      } else if (newInterval[1] < interval[0]) {
        ans.push_back(interval);
      } else {
        start = min(start, interval[0]);
        end = max(end, interval[1]);
      }
    }
    ans.insert(ans.begin() + cur, {start, end});
    return ans;
  }
};