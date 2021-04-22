/*
Author: Tony Hsiao
Date: 2021/03/28
Topic: 1570. Dot Product of Two Sparse Vectors
Speed: 180 ms, 174.3 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;

class SparseVector {
public:
  SparseVector(vector<int> &nums) {
    values = nums;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        nonzero_values.push_back(std::pair<int, int>(i, nums[i]));
      }
    }
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int dot = 0;
    for (const auto& values: nonzero_values) {
      dot += values.second * vec.values[values.first];
    }
    return dot;
  }
  std::vector<std::pair<int, int>> nonzero_values;
  std::vector<int> values;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
