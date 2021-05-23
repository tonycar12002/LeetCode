/*
Author: Tony Hsiao
Date: 2021/05/15
Topic: 1641. Count Sorted Vowel Strings
Speed: 0 ms, 5.9 MB
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
  int countVowelStrings(int n) {
    if (n == 1)
      return 5;
    std::vector<int> tmp(5, 1);
    for (int i = 1; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < 5; ++j) {
        sum += tmp[j];
        tmp[j] = sum;
      }
    }
    return tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4];
  }
};