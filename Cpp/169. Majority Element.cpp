/*
Author: Tony Hsiao
Date: 2020/04/10
Topic: 169. Majority Element
Speed: 28 ms, 9 MB
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
    int majorityElement(vector<int>& nums) {
        // unordered_map is hash table, which will faster than map(red-black tree)
        unordered_map<int, int> counter;
        for (auto i:nums) {
            counter[i]++;
            if (counter[i] > nums.size()/2)
                return i;
        }
        return -1;
    }
};