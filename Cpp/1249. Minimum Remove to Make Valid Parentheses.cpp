/*
Author: Tony Hsiao
Date: 2021/05/07
Topic: 1249. Minimum Remove to Make Valid Parentheses
Speed: 20 ms, 9.8 MB
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
  string minRemoveToMakeValid(string s) {
    std::vector<int> q;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        q.push_back(i);
      } else if (s[i] == ')') {
        if (q.size() == 0)
          s[i] = '*';
        else
          q.pop_back();
      }
    }
    for (auto &i : q)
      s[i] = '*';
    s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
    return s;
  }
};