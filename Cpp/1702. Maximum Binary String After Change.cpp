/*
Author: Tony Hsiao
Date: 2021/05/23
Topic: 1702. Maximum Binary String After Change
Speed: 156 ms, 40.4 MB
Note: method https://leetcode-cn.com/problems/maximum-binary-string-after-change/solution/maximum-binary-string-after-change-by-ik-tugt/
      be careful about all 1 string
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
  string maximumBinaryString(string binary) {
    int left = 0;
    int zero = 0;
    bool flag = true;
    for (auto &c : binary) {
      if (c == '0') {
        flag = false;
        zero++;
      } else if (c == '1' && flag){
        left++;
      }
      c= '1';
    }
    if (left == binary.size())
      return binary;
    binary[left + zero - 1] = '0';
    return binary;
  }
};