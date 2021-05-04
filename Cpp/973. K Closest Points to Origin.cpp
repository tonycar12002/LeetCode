/*
Author: Tony Hsiao
Date: 2021/05/03
Topic: 973. K Closest Points to Origin
Speed: 212 ms, 73.7 MB
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
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    std::map<float, std::vector<std::vector<int>>> ans_map;
    float ans_max_dis = INT32_MAX;
    int map_size = 0;
    for (const auto& point : points) {
      float dis = sqrt(point[0] * point[0] + point[1] * point[1]);
      if (map_size < k) {
        ans_map[dis].push_back(point);
        map_size++;
        if (ans_max_dis == INT32_MAX || ans_max_dis < dis)
          ans_max_dis = dis;
      } else if (ans_max_dis > dis) {
        if (ans_map.rbegin()->second.size() == 1) {
          ans_map.erase(ans_map.rbegin()->first);
        } else {
          ans_map.rbegin()->second.pop_back();
        }
        ans_map[dis].push_back(point);
        ans_max_dis = ans_map.rbegin()->first;
      }
    } // end for
    std::vector<std::vector<int>> ans;
    for (const auto& [key, value] : ans_map)
      for (const auto& v : value)
        ans.push_back(v);
    return ans;
  }
};