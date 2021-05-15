/*
Author: Tony Hsiao
Date: 2021/05/10
Topic: 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
Speed: 68 ms, 32.1 MB
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
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    horizontalCuts.push_back(h);
    verticalCuts.push_back(w);
    horizontalCuts.push_back(0);
    verticalCuts.push_back(0);
    std::sort(horizontalCuts.begin(), horizontalCuts.end());
    std::sort(verticalCuts.begin(), verticalCuts.end());
    long long max_h = 0, max_w = 0;
    for (int i = 1; i < horizontalCuts.size(); ++i) {
      long long dif = horizontalCuts[i] - horizontalCuts[i - 1];
      max_h = max_h > dif ? max_h : dif;
    }
    for (int i = 1; i < verticalCuts.size(); ++i) {
      long long dif = verticalCuts[i] - verticalCuts[i - 1];
      max_w = max_w > dif ? max_w : dif;
    }
    return ((long long)max_h * max_w) % 1000000007;
  }
};