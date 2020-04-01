/*
Author: Tony Hsiao
Date: 2020/03/31
Topic: 131. Palindrome Partitioning
Speed: 88 ms, 23.9 MB
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
    std::vector<std::vector<std::string>> ans;
    bool IsPalindrome(std::string s) {
        int mid = s.size();
        if (mid == 1)
            return true;
        mid = mid - 1;
        int l, r;
        if (mid % 2 == 0) {
            mid = mid / 2;
            l = mid - 1, r = mid + 1;
        }
        else {
            mid = mid / 2;
            l = mid, r = mid + 1;
        }
        while (l >= 0 && r<s.size()) {
            if (s[l] != s[r])
                return false;
            l--;
            r++;
        }
        return true;
    }
    void Recursive(std::vector<std::string>& current_ans, int start, std::string s) {
        for(int len=1; len<=s.size()-start; ++len) {
            std::string sub_string = s.substr(start, len);
            if (IsPalindrome(sub_string)) {
                //cout << "start = " << start << ", len = " << len << ", sub_string = " << sub_string << endl;
                current_ans.push_back(sub_string);
                if (start+len == s.size()) {
                    ans.push_back(current_ans);
                }
                else {
                    Recursive(current_ans, start+len, s);
                }
                current_ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        std::vector<std::string> tmp;
        Recursive(tmp, 0, s) ;
        return ans;
    }
};