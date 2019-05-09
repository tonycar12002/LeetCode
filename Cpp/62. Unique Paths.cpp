/*
Author: Tony Hsiao
Date: 2019/05/09
Topic:  62. Unique Paths
Speed: 4ms, 8.9MB
Note: Dynamic Programming
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp_table(m, vector<int>(n, 0));

        for(int i=0;i<m;i++)
            dp_table[i][0] = 1;
        for(int i=0;i<n;i++)
            dp_table[0][i] = 1;

        for(int y=1;y<m;y++){
            for(int x=1;x<n;x++){
                dp_table[y][x] = dp_table[y-1][x] + dp_table[y][x-1];
            }
        }
        return dp_table[m-1][n-1];
    }
};