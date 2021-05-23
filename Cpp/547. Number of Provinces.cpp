/*
Author: Tony Hsiao
Date: 2021/05/16
Topic: 547. Number of Provinces
Speed: 12 ms, 14.2 MB
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
  int findCircleNum(vector<vector<int>>& isConnected) {
    std::vector<std::unordered_set<int>> ans;
    for (int y = 0; y < isConnected.size(); ++y) {
      for (int x = 0; x <= y; ++x) {
        if (isConnected[y][x] == 0)
          continue;
        int find_x = -1, find_y = -1;
        int i = 0;
        for(i = 0; i < ans.size(); ++i) {
          if (find_x == -1 && ans[i].find(x) != ans[i].end())
            find_x = i;
          if (find_y == -1 && ans[i].find(y) != ans[i].end())
            find_y = i;
          if (find_x != -1 && find_y != -1)
            break;
        }  // end for
        if (find_x == -1 && find_y == -1) {
          ans.push_back({x, y});
        } else if (find_x == -1 && find_y != -1) {
          ans[find_y].insert(x);
        } else if (find_y == -1 && find_x != -1) {
          ans[find_x].insert(y);
        } else if (find_x != find_y) {
          // merge two set
          ans[find_x].merge(ans[find_y]);
          ans.erase(ans.begin() + find_y);
        }
      }
    }  // end double for
    return ans.size();
  }
};