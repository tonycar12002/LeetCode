/*
Author: Tony Hsiao
Date: 2020/04/10
Topic: 171. Excel Sheet Column Number
Speed: 0 ms, 5.9 MB
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
    int titleToNumber(string s) {
        unsigned long long int num = 0;
        for(int i=0; i<s.size(); ++i) {
            num = num * 26 + (s[i]-'A' + 1);
        }
        return num;
    }
};