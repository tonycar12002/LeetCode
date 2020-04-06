/*
Author: Tony Hsiao
Date: 2020/04/06
Topic: 12. Integer to Roman
Speed: 68 ms, 12.2 MB
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
    string intToRoman(int num) {
        vector<string> thousand = {"", "M", "MM", "MMM"};
        vector<string> hundred = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> ten = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> one = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return thousand[num/1000%10] + hundred[num/100%10] + ten[num/10%10] + one[num%10];
    }
};