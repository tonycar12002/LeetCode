/*
Author: Tony Hsiao
Date: 2021/05/28
Topic: 939. Minimum Area Rectangle
Speed: 720 ms, 19.6 MB
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
  int minAreaRect(std::vector<std::vector<int>>& points) {
    std::map<std::pair<int, int>, int> table;
    float min_area = INT_MAX;
    for (const auto& point : points) {
      table[{point[0], point[1]}] = 1;
    }
    for (const auto& point : points) {
      for (const auto& [record, num] : table) {
        if (record.first == point[0] || record.second == point[1])
          continue;
        if (table.find({record.first , point[1]}) != table.end() &&
            table.find({point[0], record.second}) != table.end() ) {
          float diff_x = fabs(record.first - point[0]);
          float diff_y = fabs(record.second - point[1]);
          min_area = min(min_area, diff_x * diff_y);
        }
      }
    }
    if (min_area == INT_MAX)
      return 0;
    return min_area;
  }
};
