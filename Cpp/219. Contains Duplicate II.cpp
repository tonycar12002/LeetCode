/*
Author: Tony Hsiao
Date: 2020/04/11
Topic: 219. Contains Duplicate II
Speed: 40 ms, 12.6 MB
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> distance;
        for (int i=0; i<nums.size(); ++i) {
            if (distance.find(nums[i]) == distance.end())
                distance[nums[i]] = i;
            else {
                if (i - distance[nums[i]] <= k)
                    return true;
                else
                    distance[nums[i]] = i;
            }
        }
        return false;
    }
};
