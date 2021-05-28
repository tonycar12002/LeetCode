/*
Author: Tony Hsiao
Date: 2021/05/23
Topic: 1254. Number of Closed Islands
Speed: 12 ms, 9.5 MB
Note: try to use std::function to solve problem
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
  int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // C++ 11 std::function
    std::function<int(int, int)> dfs =
        [&] (int x, int y) {
          if (grid[y][x] == 1)
            return 1;
          if (x <= 0 || y <= 0 || x >=  m - 1 || y >= n - 1)
            return 0;
          grid[y][x] = 1;
          return dfs(x + 1, y) & dfs(x, y - 1) & dfs(x - 1, y) & dfs(x, y + 1);
        };

    int ans = 0;
    for (int y = 1; y < n - 1; ++y)
      for (int x = 1; x < m - 1; ++x)
        if (!grid[y][x])
          ans += dfs(x, y);
    return ans;
  }
};