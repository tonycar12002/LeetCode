/*
Author: Tony Hsiao
Date: 2021/05/23
Topic: 1525. Number of Good Ways to Split a String
Speed: 48 ms, 11.3 MB
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
  int numSplits(string s) {
    int left = 0;
    int right = s.size() - 1;
    int mid;
    // <character value, index>
    std::unordered_map<int, std::stack<int>> first;
    std::unordered_map<int, std::stack<int>> second;
    while (left <= right) {
      int r_c = s[right] - 'a';
      int l_c = s[left] - 'a';
      if (first.size() > second.size()) {
        second[r_c].push(right);
        right--;
      } else if (first.size() < second.size()) {
        first[l_c].push(left);
        left++;
      } else {
        if (first.find(l_c) != first.end()) {
          first[l_c].push(left);
          left++;
        } else if (second.find(r_c) != second.end()) {
          second[r_c].push(right);
          right--;
        } else {
          first[l_c].push(left);
          left++;
        }
      }
    }
    if (first.size() != second.size())
      return 0;
    int ans = 1;
    std::swap(left, right);
    while(left >= 0) {
      int val = s[left] - 'a';
      // not exist in second string
      if (second[val].size() == 0)
        break;
      // only one in first string
      if (first[val].size() <= 1)
        break;
      first[val].pop();
      left--;
      ans++;
    }
    return ans;
  }
};