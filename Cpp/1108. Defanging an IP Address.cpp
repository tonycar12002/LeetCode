/*
Author: Tony Hsiao
Date: 2021/03/28
Topic: 1108. Defanging an IP Address
Speed: 0 ms, 5.8 MB
Note: 超級沒意義的一題目
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
    string defangIPaddr(string address) {
      std::string ans = "";
      for (int i = 0; i < address.size(); ++i) {
        if (address[i] == '.')
          ans += "[.]";
        else
          ans += address[i];
      }
      return ans;
    }
};