/*
Author: Tony Hsiao
Date: 2020/04/08
Topic: 120. Triangle
Speed: 4 ms, 7.5 MB
Note: Dynamic programiing
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
    int min(int x, int y) {
        return (x<y) ? x : y;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> min_path;
        int ans = INT_MAX;
        for (int y=0; y<triangle.size(); ++y) {
            min_path.push_back(vector<int>(triangle[y].size(), 0));
        }
        for (int y=0; y<triangle.size(); ++y) {
            for (int x=0; x<triangle[y].size(); ++x) {
                if (y == 0)
                    min_path[y][x] = triangle[y][x];
                else if (x > 0 && x != triangle[y].size() - 1) // Normal 
                    min_path[y][x] = triangle[y][x] + min(min_path[y-1][x], min_path[y-1][x-1]);
                else if (x == triangle[y].size() - 1) // rightmost
                    min_path[y][x] = triangle[y][x] + min_path[y-1][x-1];
                else  // leftmost
                    min_path[y][x] = triangle[y][x] + min_path[y-1][x];
                
                if (y == triangle.size() - 1) 
                    ans = min(ans, min_path[y][x]);
            }
        }
        return ans;
    }
};