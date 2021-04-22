/*
Author: Tony Hsiao
Date: 2021/03/28
Topic: 1480. Running Sum of 1d Array
Speed: 4 ms, 8.5 MB
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
  vector<int> runningSum(vector<int>& nums) {
    int current_sum = 0;
    for (auto& num : nums) {
      num += current_sum;
      current_sum = num;
    }
    return nums;
  }
};