/*
Author: Tony Hsiao
Date: 2021/05/13
Topic: 322. Coin Change
Speed: 88 ms, 14.4 MB
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
  int coinChange(vector<int>& coins, int amount) {
    std::vector<int> ans(amount + 1, amount + 1);
    ans[0] = 0;
    for (size_t i = 0; i <= amount; ++i) {
      for (size_t j = 0; j < coins.size(); ++j) {
        if (i < coins[j])
          continue;
        ans[i] = min(ans[i - coins[j]] + 1, ans[i]);
      }
    }
    return (ans[amount] <= amount) ? ans[amount] : -1;
  }
};