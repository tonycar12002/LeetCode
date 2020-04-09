/*
Author: Tony Hsiao
Date: 2020/04/09
Topic: 125. Valid Palindrome
Speed: 8 ms, 7.8 MB
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
    bool isPalindrome(string s) {
        string s_new = "";
        for (auto i : s) {
            if (i >= 'A' && i <= 'Z')
                s_new += (i + ' ');
            else if (i >= 'a' && i <= 'z')
                s_new += i;
            else if (i >= '0' && i <= '9')
                s_new += i;
        }
        //cout << s_new << endl;
        int left = 0, right = s_new.size() - 1;
        while (left <= right) {
            if (s_new[left] != s_new[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};