/*
Author: Tony Hsiao
Date: 2019/11/20
Topic: 64. Minimum Path Sum
Speed: 8 ms, 11 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<std::vector<int>> ans(grid);
        
        for (int y=0; y<m; ++y) {
            for (int x=0; x<n; ++x) {
                if (y == 0 && x == 0)
                    ans[y][x] = grid[y][x];
                else if (y == 0)
                    ans[y][x] = ans[y][x-1] + grid[y][x];
                else if(x == 0)
                    ans[y][x] = ans[y-1][x] + grid[y][x];
                else
                    ans[y][x] = 
                        std::min(ans[y][x-1] + grid[y][x], ans[y-1][x] + grid[y][x]);
            }
        }
        return ans[m-1][n-1];
    }
};