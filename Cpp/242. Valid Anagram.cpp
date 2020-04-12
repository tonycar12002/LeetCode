/*
Author: Tony Hsiao
Date: 2020/04/13
Topic: 242. Valid Anagram
Speed: 8 ms, 7.5 MB
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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> table(26, 0);
        for (auto i:s)
            table[i-'a']++;
        for (auto i:t) 
            table[i-'a']--;
        for (int i=0; i<26; ++i)
            if (table[i] != 0)
                return false;
        return true;
    }
};