/*
Author: Tony Hsiao
Date: 2020/03/26
Topic: 34. Find First and Last Position of Element in Sorted Array
Speed: 8 ms, 8 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;
        bool found = false;
        
        while(left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                found = true;
                break;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        vector<int>range;
        if (found) {
            left = mid;
            right = mid;
            while(nums[left] == target) {
                left --;
                if (left < 0) {
                    break;
                }
            }
            while(nums[right] == target) {
                right++;
                if (right == nums.size()) {
                    break;
                }
            }
            range.push_back(left + 1);
            range.push_back(right - 1);
            
        } 
        else {
            range.push_back(-1);
            range.push_back(-1);
        }
        return range;
    }
};