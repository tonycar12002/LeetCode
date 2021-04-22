/*
Author: Tony Hsiao
Date: 2021/03/28
Topic: 1119. Remove Vowels from a String
Speed: 0 ms, 6.3 MB
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
    string removeVowels(string s) {
      std::string ans = "";
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
          ans += s[i];
      }
      return ans;
    }
};