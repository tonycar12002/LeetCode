/*
Author: Tony Hsiao
Date: 2020/04/11
Topic: 217. Contains Duplicate
Speed:  ms,  MB
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
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> table;
        for (int i:nums) {
            table[i]++;
            if (table[i] > 1)
                return true;
        }
        return false;
    }
};