/*
Author: Tony Hsiao
Date: 2020/03/26
Topic: 13. Roman to Integer
Speed: 12 ms, 8.5 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int>roman_table;
        roman_table['I'] = 1;
        roman_table['V'] = 5;
        roman_table['X'] = 10;
        roman_table['L'] = 50;
        roman_table['C'] = 100;
        roman_table['D'] = 500;
        roman_table['M'] = 1000;
        int number = 0;
        for (int i=0; i<s.size(); ++i) {
            //cout << i << " " << number << endl;
            if (i == s.size() - 1)
                number += roman_table[s[i]];
            else if (s[i] == 'I') {
                if (s[i+1] == 'V' || s[i+1] == 'X')
                    number -= 1;
                else
                    number += 1;
            }
            else if (s[i]== 'X') {
                if (s[i+1] == 'L' || s[i+1] == 'C')
                    number -= 10;
                else
                    number += 10;
            }
            else if (s[i] == 'C') {
                if (s[i+1] == 'D' || s[i+1] == 'M')
                    number -= 100;
                else
                    number += 100;
            }
            else {
                number += roman_table[s[i]];
            }
        } // for
        return number;
    }
};