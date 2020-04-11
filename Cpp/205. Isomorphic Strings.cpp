/*
Author: Tony Hsiao
Date: 2020/04/11
Topic: 205. Isomorphic Strings
Speed: 8 ms, 7 MB
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
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<char> change_table_st(150, '0');
        vector<char> change_table_ts(150, '0');
        
        for (int i=0; i<t.size(); ++i) {
            int alphabet_s = s[i];
            int alphabet_t = t[i];
            if (change_table_ts[alphabet_t] == '0')
                change_table_ts[alphabet_t] = s[i];
            
            if (change_table_st[alphabet_s] == '0')
                change_table_st[alphabet_s] = t[i];
            
            if (change_table_st[alphabet_s] != t[i] || change_table_ts[alphabet_t] != s[i])
                return false;
        }
        return true;
    }
};