/*
Author: Tony Hsiao
Date: 2020/03/31
Topic: 35. Search Insert Position
Speed: 4 ms, 7 MB
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
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (nums[mid] > target)
            return mid;
        else
            return mid + 1;
    }
};