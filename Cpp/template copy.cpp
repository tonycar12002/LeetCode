/*
Author: Tony Hsiao
Date: 2019/11/20
Topic: 394. Decode String
Speed:  ms,  MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<int> bracket;
    map<int, string> record_string;
    int tmp_num = 0;
    for (int i=0; i<s.size(); ++i) {
      if (s[i] == '[') {
        bracket.push(i);
      }
      else if (s[i] == ']') {
        // deal with string
      }
      else {

      }
    }
  }
};