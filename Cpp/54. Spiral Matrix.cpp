/*
Author: Tony Hsiao
Date: 2020/04/06
Topic: 54. Spiral Matrix
Speed: 0 ms, 6.3 MB
Note: matrix of m x n, 走的順序為 y=0 => x=n-1 => y=m-1 => x=0 => y=1
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
        return (x>y) ? y : x;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int x_start = 0, x_end = n - 1;
        int y_start = 0, y_end = m - 1;
        int counter = 0;
        while (counter < min(m, n) * 2 -1 && x_start <= x_end && y_start <= y_end) {
            if (counter % 4 == 0) {
                for (int i=x_start; i<=x_end; ++i)
                    ans.push_back(matrix[y_start][i]);
                y_start++;
            }
            else if (counter % 4 == 1) {
                for (int i=y_start; i<=y_end; ++i)
                    ans.push_back(matrix[i][x_end]);
                x_end--;
            }
            else if (counter % 4 == 2) {
                for (int i=x_end; i>=x_start; --i)
                    ans.push_back(matrix[y_end][i]);
                y_end--;
            }
            else {
                for (int i=y_end; i>=y_start; --i)
                    ans.push_back(matrix[i][x_start]);
                x_start++;
            }
            counter++;
        }
        return ans;
    }
};