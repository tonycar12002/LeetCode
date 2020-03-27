/*
Author: Tony Hsiao
Date: 2020/03/27
Topic: 76. Minimum Window Substring
Speed: 52 ms, 16.3 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        list<pair<int, int>> element_index; // alphabet-'A', index
        map<char, int>record; // alphabet, counts
        int cnt = 0, start = 0, len = INT_MAX;
        string ans;
        for (char& c: t) {
            record[c]++;
        }
        for (int i=0; i<s.size(); ++i) {
            if (--record[s[i]] >= 0) {
                cnt++;
            }
            while (cnt == t.size()) { // found all elements 
                if (i - start + 1 < len) {
                    len = i - start + 1;
                    ans = s.substr(start, len);
                    //cout << ans  << ", len = " << len << endl;
                }
                //cout << s[start] << " " << record[s[start]] << endl;
                if (record[s[start]] >= 0) { // s[start] in t
                    cnt--;
                }
                record[s[start]]++;
                start++;
            }
        }
        if (len != INT_MAX)
            return ans;
        else
            return "";
    }
};
  