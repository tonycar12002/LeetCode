/*
Author: Tony Hsiao
Date: 2020/04/10
Topic: 168. Excel Sheet Column Title
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
    string convertToTitle(int n) {
        string ans = "";
        while (n > 0) {
            int tmp = n % 26;
            if (tmp == 0) {
                tmp = 26;  
                n = n / 26 - 1; 
            }
            else {
               n = n / 26; 
            }
            char alphabet = static_cast<char>(tmp + 'A' - 1);
            ans = alphabet + ans;
        }
        return ans;
    }
};
