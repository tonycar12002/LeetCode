/*
Author: Tony Hsiao
Date: 2020/04/06
Topic: 43. Multiply Strings
Speed: 16 ms, 6.8 MB
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
    string multiply(string num1, string num2) {
        int size_1 = num1.size(), size_2 = num2.size();
        vector<int> ans(size_2 + size_1, 0);
        for (int i=0; i<size_1; ++i) {
            for (int j=0; j<size_2; ++j) {
                ans[i+j] += (num1[size_1 - i - 1] - '0') * (num2[size_2 - j - 1] - '0');
            }
        }
        for (int i=0; i<size_1+size_2; ++i) {
            if (ans[i] >= 10) {
                ans[i+1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }
        string ans_string = "";
        bool un_zero = false;
        for (int i=size_2+size_1-1 ;i>=0; --i) {
            if (ans[i] != 0 && un_zero == false)
                un_zero = true;
            if (un_zero) {
                ans_string += ans[i]+'0';
            }
        }
        return ans_string;
    }
};