/*
Author: Tony Hsiao
Date: 2021/05/15
Topic: 1314. Matrix Block Sum
Speed: 16 ms, 9.6 MB
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
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    vector<vector<int>> sum(mat.size(), vector<int>(mat[0].size(), 0));
    vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
    for (int j = 0; j < mat.size(); ++j) {
      for (int i = 0; i < mat[0].size(); ++i) {
        if (j > 0 && i > 0)
          sum[j][i] = mat[j][i] + sum[j - 1][i] + sum[j][i - 1] - sum[j - 1][i - 1];
        else if (j > 0)
          sum[j][i] = mat[j][i] + sum[j - 1][i];
        else if (i > 0)
          sum[j][i] = mat[j][i] + sum[j][i - 1];
        else
          sum[j][i] = mat[j][i];
      }
    }
    for (int j = 0; j < mat.size(); ++j) {
      for (int i = 0; i < mat[0].size(); ++i) {
        int start_x = i - k, start_y = j - k;
        int end_x = i + k, end_y = j + k;
        start_x = (start_x < 0) ? 0 : start_x;
        start_y = (start_y < 0) ? 0 : start_y;
        end_x = (end_x >= mat[0].size()) ? mat[0].size() - 1 : end_x;
        end_y = (end_y >= mat.size()) ? mat.size() - 1 : end_y;
        if (start_x != 0 && start_y != 0) {
          ans[j][i] = sum[end_y][end_x] - sum[end_y][start_x - 1] - sum[start_y - 1][end_x] + sum[start_y - 1][start_x - 1];
        } else if (start_y == 0 && start_x != 0) {
          ans[j][i] = sum[end_y][end_x] - sum[end_y][start_x - 1];
        } else if (start_x == 0 && start_y != 0) {
          ans[j][i] = sum[end_y][end_x] - sum[start_y - 1][end_x];
        } else {
          ans[j][i] = sum[end_y][end_x];
        }
      }
    }
    return ans;
  }
};