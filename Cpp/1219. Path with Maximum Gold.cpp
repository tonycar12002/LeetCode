/*
Author: Tony Hsiao
Date: 2021/05/24
Topic: 1219. Path with Maximum Gold
Speed: 40 ms, 7.4 MB
Note: Do not allocate new 2d vector, it will cause TLE
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
  int DFS(vector<vector<int>>& grid, int x, int y) {
    int value = grid[y][x];
    grid[y][x] = 0;
    int max_route = 0;
    int next_x = x - 1;
    int next_y = y;
    if (next_x >= 0 && next_y >= 0 && next_x < grid[0].size() &&
        next_y < grid.size() && grid[next_y][next_x] != 0) {
      max_route = max(max_route, DFS(grid, next_x, next_y));
    }
    next_x = x + 1;
    next_y = y;
    if (next_x >= 0 && next_y >= 0 && next_x < grid[0].size() &&
        next_y < grid.size() && grid[next_y][next_x] != 0) {
      max_route = max(max_route, DFS(grid, next_x, next_y));
    }
    next_x = x;
    next_y = y + 1;
    if (next_x >= 0 && next_y >= 0 && next_x < grid[0].size() &&
        next_y < grid.size() && grid[next_y][next_x] != 0) {
      max_route = max(max_route, DFS(grid, next_x, next_y));
    }
    next_x = x;
    next_y = y - 1;
    if (next_x >= 0 && next_y >= 0 && next_x < grid[0].size() &&
        next_y < grid.size() && grid[next_y][next_x] != 0) {
      max_route = max(max_route, DFS(grid, next_x, next_y));
    }
    grid[y][x] = value;
    return max_route + value;
  }

  int getMaximumGold(vector<vector<int>>& grid) {
    if (grid.size() == 0)
      return 0;
    int max_gold = 0;
    for(int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] != 0) {
          max_gold = max(max_gold, DFS(grid, j, i));
        }
      }
    }
    return max_gold;
  }
};