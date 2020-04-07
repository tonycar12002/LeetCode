/*
Author: Tony Hsiao
Date: 2020/04/06
Topic: 59. Spiral Matrix II
Speed: 0 ms, 6.5 MB
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x_start = 0, x_end = n - 1;
        int y_start = 0, y_end = n - 1;
        int nums = 1, counter = 0;
        while (nums <= n*n  && x_start <= x_end && y_start <= y_end) {
            if (counter % 4 == 0) {
                for (int i=x_start; i<=x_end; ++i) {
                    ans[y_start][i] = nums;
                    nums++;
                }
                y_start++;
            }
            else if (counter % 4 == 1) {
                for (int i=y_start; i<=y_end; ++i) {
                    ans[i][x_end] = nums;
                    nums++;
                }
                x_end--;
            }
            else if (counter % 4 == 2) {
                for (int i=x_end; i>=x_start; --i) {
                    ans[y_end][i] = nums;
                    nums++;
                }
                y_end--;
            }
            else {
                for (int i=y_end; i>=y_start; --i) {
                    ans[i][x_start] = nums;
                    nums++;
                }
                x_start++;
            }
            counter++;
        }
        return ans;
    }
};