/*
Author: Tony Hsiao
Date: 2021/05/11
Topic: 1010. Pairs of Songs With Total Durations Divisible by 60
Speed: 28 ms, 23.2 MB
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
  int numPairsDivisibleBy60(vector<int>& time) {
    std::vector<int> table(60, 0);
    int ans = 0;
    for (const auto& t : time) {
      ans += table[(60 - (t % 60)) % 60];
      table[(t % 60)] += 1;
    }
    return ans;
  }
};