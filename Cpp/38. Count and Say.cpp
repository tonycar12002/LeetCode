/*
Author: Tony Hsiao
Date: 2020/04/09
Topic: 38. Count and Say
Speed: 4 ms, 56.8 MB
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
    string countAndSay(int n) {
        string num = "1";
        for (int i=1; i<n; ++i) {
            char last_element = ' ';
            int counter = 0;
            string new_num = "";
            for (int j=0; j<num.size(); ++j) {
                if (j != 0 && num[j] != last_element) {
                    new_num = new_num + std::to_string(counter) + last_element;
                    counter = 0;
                }
                last_element = num[j];
                counter++;
            }
            new_num = new_num + std::to_string(counter) + last_element;
            num = new_num;
        }
        
        return num;
    }
};