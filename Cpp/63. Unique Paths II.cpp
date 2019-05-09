/*
Author: Tony Hsiao
Date: 2019/05/09
Topic: 63. Unique Paths II
Speed: 4ms, 9.3MB
Note: Dynmaic Programming
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp_table(m, vector<long long>(n, 0));

        (obstacleGrid[0][0] == 1) ? dp_table[0][0] = 0 : dp_table[0][0] = 1 ; 
        for(int i=1;i<m;i++) // first column
            (obstacleGrid[i][0] == 1) ? dp_table[i][0] = 0 : dp_table[i][0] = dp_table[i-1][0];
                
        for(int i=1;i<n;i++) // first row
            (obstacleGrid[0][i] == 1) ? dp_table[0][i] = 0 : dp_table[0][i] = dp_table[0][i-1];

        for(int y=1;y<m;y++)
            for(int x=1;x<n;x++)
                (obstacleGrid[y][x] == 1) ? dp_table[y][x] = 0 : dp_table[y][x] = dp_table[y-1][x] + dp_table[y][x-1];
        return dp_table[m-1][n-1];
    }
};