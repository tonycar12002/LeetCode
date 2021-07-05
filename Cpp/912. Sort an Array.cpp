/*
Author: Tony Hsiao
Date: 2021/05/28
Topic: 912. Sort an Array
Speed: 380 ms, 185 MB
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
  vector<int> CombineArray(const std::vector<int>& first, const std::vector<int>& second) {
    int index_1 = 0, index_2 = 0;
    std::vector<int> combine_vector;
    while (index_1 != first.size() && index_2 != second.size()) {
      if (first[index_1] >= second[index_2]) {
        combine_vector.emplace_back(second[index_2++]);
      } else {
        combine_vector.emplace_back(first[index_1++]);
      }
    }
    while (index_1 != first.size())
      combine_vector.emplace_back(first[index_1++]);
    while (index_2 != second.size())
      combine_vector.emplace_back(second[index_2++]);
    return combine_vector;
  }

  vector<int> MergeSort(const std::vector<int>& nums, int left, int right) {
    if (right < left)
      return {};
    if (left == right)
      return {nums[left]};
    int mid = (left + right) / 2;
    auto new_left = MergeSort(nums, left, mid);
    auto new_right = MergeSort(nums, mid + 1, right);
    auto combine = CombineArray(new_left, new_right);
    return combine;
  }

  vector<int> sortArray(vector<int>& nums) {
    return MergeSort(nums, 0, nums.size() - 1);
  }
};