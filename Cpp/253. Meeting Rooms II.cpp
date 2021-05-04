/*
Author: Tony Hsiao
Date: 2021/05/03
Topic: 253. Meeting Rooms II
Speed: 12 ms, 11.8 MB
Note: priority queue
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
  int minMeetingRooms(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [=](const std::vector<int>& a, const std::vector<int>& b) {
      return a[0] < b[0];
    });
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (const auto& interval : intervals) {
      if (!q.empty() && q.top() <= interval[0])
        q.pop();
      q.push(interval[1]);
    }
    return q.size();
  }
};