/*
Author: Tony Hsiao
Date: 2021/05/16
Topic: 1277. Count Square Submatrices with All Ones
Speed: 88 ms, 23.6 MB
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
  int countSquares(vector<vector<int>>& matrix) {
    int ans = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == 1) {
          if (i > 0 && j > 0) {
            matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1]);
            matrix[i][j] = min(matrix[i][j], matrix[i - 1][j - 1]) + 1;
          } else {
            matrix[i][j] = 1;
          }
          ans += matrix[i][j];
        } else {
          matrix[i][j] = 0;
        }
      }
    }
    return ans;
  }
};