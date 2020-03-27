/*
Author: Tony Hsiao
Date: 2020/03/27
Topic: 91. Decode Ways
Speed: 0 ms, 6.5 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0')
            return 0;
        int ans[s.size()+1];
        ans[0] = 1;
        ans[1] = 1;
        for (int i=1; i<s.size(); ++i) {
            int tmp = (s[i]-48) + (s[i-1]-48)*10;
            if (s[i] - 48 == 0 && tmp != 10 && tmp != 20)
                return 0;
            if (tmp == 10 || tmp == 20) {
                ans[i] = 0;
                ans[i+1] = ans[i-1];
            }
            else if (tmp <= 26)
                ans[i+1] = ans[i] + ans[i-1];
            else
                ans[i+1] = ans[i];
        }   
        return ans[s.size()];
    }
};


