/*
Author: Tony Hsiao
Date: 2020/04/08
Topic: 93. Restore IP Addresses
Speed: 0 ms, 6.5 MB
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
    vector<string> ans;
    bool isValid(string s) {
        if (s.size() == 0 || s.size() >= 4)
            return false;
        int num = stoi(s); 
        if (s.size() == 1 && s[0] == '0')
            return true;
        return (num <=255 && num >= 1 && s[0] != '0');
    }
    void BruteForce(string s, int split, string current_ans) {
        string substring, tmp_s;
        for (int i=1; i<=3; ++i) {
            if (s.size() <= i)
                break;
            substring = s.substr(0, i); 
            if (isValid(substring)) {
                tmp_s = s.substr(i, s.size()-i);
                //cout << s << " " << tmp_s << endl;
                if (split != 2)
                    BruteForce(tmp_s, split+1, current_ans + substring + ".");
                else {
                    if (isValid(tmp_s)) {
                         ans.push_back(current_ans + substring + "." + tmp_s);
                    }
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() != 0)
            BruteForce(s, 0, "");
        return ans;
    }
};