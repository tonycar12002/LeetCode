/*
Author: Tony Hsiao
Date: 2021/05/15
Topic: 746. Min Cost Climbing Stairs
Speed: 8 ms, 13.8 MB
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
  int minCostClimbingStairs(vector<int>& cost) {
    std::vector<int> min_cost(cost.size() + 2, 0);
    min_cost[0] = 0;
    min_cost[1] = 0;
    for (int i = 0; i < cost.size(); ++i) {
      min_cost[i + 2] = min(min_cost[i] + cost[i], min_cost[i + 1] + cost[i]);
    }
    return min(min_cost[cost.size() + 1], min_cost[cost.size()]);
  }
};