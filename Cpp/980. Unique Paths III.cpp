/*
Author: Tony Hsiao
Date: 2019/05/09
Topic: 980. Unique Paths III
Speed: 4 ms, 8.8 MB
Note: 題目為尋找起點到終點，可以經過所有0的路徑數量，意指正確路徑需走過所有0且不能重複走
DFS Brute Force O(4^(m*n)), grid size 很小(<=20)故不會花費太多時間
*/
class Solution {
private:
    int zero_counter = 0;
    int m;
    int n;
public:
    int DFS(vector<vector<int>>&grid, int x, int y, int cur_zero){
        if(x<0 || y <0 || x>=n || y>=m)
            return 0;
        if(grid[y][x] == 2)
            return (cur_zero == zero_counter+1) ? 1 : 0;
        if(grid[y][x] == -1)
            return 0;
        
        cur_zero += 1;
        grid[y][x] = -1; // mark as visited
        
        int cur_res = DFS(grid, x-1, y, cur_zero) + \
                      DFS(grid, x, y-1, cur_zero) + \
                      DFS(grid, x+1, y, cur_zero) + \
                      DFS(grid, x, y+1, cur_zero);

        grid[y][x] = 0;
        return cur_res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int st_x, st_y;
        for(int y=0;y<m;y++){
            for(int x=0;x<n;x++){
                if(grid[y][x] == 1)
                    st_x = x, st_y =y;
                else if(grid[y][x] == 0)
                    zero_counter += 1;
            }
        }
        
        return DFS(grid, st_x, st_y, 0);
    }
};