/*
Author: Tony Hsiao
Date: 2021/05/03
Topic: 767. Reorganize String
Speed:  ms,  MB
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
  string reorganizeString(string S) {
    if (S.size() <= 1)
      return S;
    for (int i = 1; i < S.size(); ++i) {
      if (S[i] == S[i - 1])
    }
  }
};