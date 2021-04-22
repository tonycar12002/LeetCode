/*
Author: Tony Hsiao
Date: 2021/04/21
Topic: 200. Number of Islands
Speed: 12 ms, 10 MB
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
  void GoThrough(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y) {
    visited[x][y] = 1;
    if (x >= 1 && grid[x - 1][y] == '1' && visited[x - 1][y] == 0)
      GoThrough(grid, visited, x - 1, y);
    if (y >= 1 && grid[x][y - 1] == '1' && visited[x][y - 1] == 0)
      GoThrough(grid, visited, x, y - 1);
    if (x < grid.size() - 1 && grid[x + 1][y] == '1' && visited[x + 1][y] == 0)
      GoThrough(grid, visited, x + 1, y);
    if (y < grid[x].size() - 1 && grid[x][y + 1] == '1' && visited[x][y + 1] == 0)
      GoThrough(grid, visited, x, y + 1);
  }
  int numIslands(vector<vector<char>>& grid) {
    std::vector<std::vector<int>> visted(grid.size(), std::vector<int>(grid[0].size(), 0));
    int ans = 0;
    for (int x = 0; x < grid.size(); ++x) {
      for (int y = 0; y < grid[x].size(); ++y) {
        if (visted[x][y] == 0 && grid[x][y] == '1') {
          GoThrough(grid, visted, x, y);
          ans += 1;
        }
      }
    }
    return ans;
  }
};