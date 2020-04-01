/*
Author: Tony Hsiao
Date: 2020/03/31
Topic: 128. Longest Consecutive Sequence
Speed: 16 ms, 8 MB
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
    int max(int x, int y) {
        return (x>y) ? x : y;
    }
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> table;
        int max_num = 0;
        for (int value:nums) {
            if (table[value] == 0) {
                table[value] = table[value-1] + table[value+1] + 1;
                if (table[value-1] != 0)
                    table[value-table[value-1]] = table[value];
                if (table[value+1] != 0)
                    table[value+table[value+1]] = table[value];
                max_num = max(max_num, table[value]);
            }
        }
        return max_num;
    }
};