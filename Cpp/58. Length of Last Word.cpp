/*
Author: Tony Hsiao
Date: 2020/04/09
Topic: 58. Length of Last Word
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
    bool isAlphabet(char c) {
        if (c >= 'A' && c <= 'Z')
            return true;
        else if (c >= 'a' && c <= 'z')
            return true;
        else
            return false;
    }
    int lengthOfLastWord(string s) {
        bool find_words = false;
        int counter = 0;
        for (int i=s.size()-1; i>=0; --i) {
            if (isAlphabet(s[i]) && !find_words) {
                find_words = true;
            }
            if (find_words && !isAlphabet(s[i])) {
                return counter;
            }
            else if (find_words) {
                counter++;
            }
        }
        return counter;
    }
};