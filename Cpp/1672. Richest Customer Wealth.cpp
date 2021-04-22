/*
Author: Tony Hsiao
Date: 2021/03/28
Topic: 1672. Richest Customer Wealth
Speed: 8 ms, 7.8 MB
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
  int maximumWealth(vector<vector<int>>& accounts) {
    int ans = -1;
    for (const auto& bank_values : accounts) {
      int values = 0;
      for (const auto& value : bank_values) {
        values += value;
      }
      ans = (values > ans) ? values : ans;
    }
    return ans;
  }
};