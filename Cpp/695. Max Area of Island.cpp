/*
Author: Tony Hsiao
Date: 2021/05/11
Topic: 695. Max Area of Island
Speed: 12 ms, 23.1 MB
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
  int DFS(vector<vector<int>>& grid, int y, int x) {
    int area = 1;
    grid[y][x] = 0;
    if (y > 0 && grid[y-1][x] == 1) {
      area += DFS(grid, y - 1, x);
    }
    if (x > 0 && grid[y][x-1] == 1) {
      area += DFS(grid, y, x - 1);
    }
    if (y < grid.size() - 1 && grid[y + 1][x] == 1) {
      area += DFS(grid, y + 1, x);
    }
    if (x < grid[y].size() - 1 && grid[y][x + 1] == 1) {
      area += DFS(grid, y, x + 1);
    }
    return area;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    for (int y = 0; y < grid.size(); ++y) {
      for (int x = 0; x < grid[y].size(); ++x) {
        if (grid[y][x] == 1) {
          int area = DFS(grid, y, x);
          max_area = max(area, max_area);
        }
      }
    }
    return max_area;
  }
};