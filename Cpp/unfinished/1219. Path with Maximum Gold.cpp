class Solution {
public:
  int DFS(vector<vector<int>> grid, int x, int y) {
    if (x < 0 || y < 0 || x >= visited[0].size() ||
        y >= visited.size() || grid[y][x] == 0)
      return 0;
    visited[y][x] = 1;
    int value = grid[y][x];
    grid[y]
    int max_route = 0;
    max_route = max(max_route, DFS(grid, x - 1, y, visited));
    max_route = max(max_route, DFS(grid, x, y - 1, visited));
    max_route = max(max_route, DFS(grid, x + 1, y, visited));
    max_route = max(max_route, DFS(grid, x, y + 1, visited));
    return max_route + value;;
  }

  int getMaximumGold(vector<vector<int>>& grid) {
    if (grid.size() == 0)
      return 0;
    int max_gold = 0;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    for(int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        auto visit = visited;
        max_gold = max(max_gold, DFS(grid, j, i, visit));
        if (max_gold == 127)
          cout << i << " " << j << endl;
      }
    }
    return max_gold;
  }
};