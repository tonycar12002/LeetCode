/*
Author: Tony Hsiao
Date: 2021/05/06
Topic: 767. Reorganize String
Speed: 0 ms, 8.6 MB
Note: sort the value by appearance time first
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
  string reorganizeString(string S) {
    std::priority_queue<std::pair<int, char>> char_record;
    int counter[26] = {0};
    for (const auto& c : S) {
      counter[c - 'a'] += 1;
    }
    std::string res = "";
    for (int i = 0; i < 26; ++i) {
      if (counter[i] * 2 >　S.size() + 1)
      return res;
      if (counter[i] != 0)
        char_record.push({counter[i], i + 'a'});
    }
    while (char_record.size() >= 2) {
      auto first = char_record.top();
      char_record.pop();
      auto second = char_record.top();
      char_record.pop();
      res = res + first.second + second.second;
      if (--first.first > 0)
        char_record.push(first);
      if (--second.first > 0)
        char_record.push(second);
    }
    if (char_record.size() != 0)
      res = res + char_record.top().second;
    return res;
  }
};