/*
Author: Tony Hsiao
Date: 2021/04/22
Topic: 1041. Robot Bounded In Circle
Speed: 0 ms, 6.2 MB
Note: 只要朝向不朝+Y，則必然致多4次就回原點
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
  bool isRobotBounded(string instructions) {
    std::vector<std::pair<int, int>> dirs = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int index = 1, x = 0, y = 0;
    for (const auto& cha : instructions) {
      if (cha == 'G') {
        x += dirs[index].first;
        y += dirs[index].second;
      } else if (cha == 'R') {
        index = (index + 1) % 4;
      } else if (cha == 'L') {
        index = (index + 3) % 4;
      }
    }
    return (dirs[index].second != 1) || ((x == y) && (x == 0));
  }
};