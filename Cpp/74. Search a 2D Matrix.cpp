/*
Author: Tony Hsiao
Date: 2021/04/26
Topic: 74. Search a 2D Matrix
Speed: 4 ms, 9.6 MB
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
  bool BinarySearch(const std::vector<int>& row, int left, int right, int target) {
    if (left > right)
      return false;
    int mid = (left + right) / 2;
    if (row[mid] == target)
      return true;
    if (row[mid] < target) {
      return BinarySearch(row, mid + 1, right, target);
    } else {
      return BinarySearch(row, left, mid - 1, target);
    }
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0)
      return false;
    if (target > matrix[matrix.size() - 1][matrix[0].size() - 1])
      return false;
    int target_row;
    for (target_row = 0; target_row < matrix.size(); target_row++) {
      if (target > matrix[target_row][0])
        continue;
      else if (target == matrix[target_row][0])
        return true;
      else
        break;
    }
    target_row -= 1;
    if (target_row == -1)
      return false;
    return BinarySearch(matrix[target_row], 0, matrix[target_row].size() - 1, target);
  }
};