/*
Author: Tony Hsiao
Date: 2021/05/15
Topic: 221. Maximal Square
Speed: 28 ms, 12 MB
Note: record記錄著最大square邊長
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
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0)
      return 0;
    vector<vector<int>> record(matrix.size(), std::vector<int>(matrix[0].size(), 0));
    int max_area = 0;
    for (int x = 0; x < matrix[0].size(); ++x) {
      for (int y = 0; y < matrix.size(); ++y) {
        if (matrix[y][x] == '1') {
          if (x == 0 || y == 0) {
            record[y][x] = 1;
          } else {
            record[y][x] = min(record[y][x - 1], min(record[y - 1][x], record[y - 1][x - 1])) + 1;
          }
          max_area = max(max_area, record[y][x] * record[y][x]);
        }
      }
    }
    return max_area;
  }
};