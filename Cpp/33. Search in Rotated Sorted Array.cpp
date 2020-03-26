/*
Author: Tony Hsiao
Date: 2020/03/26
Topic: 33. Search in Rotated Sorted Array
Speed: 4 ms, 6.7 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;
        while (left<=right) {
            mid = (left + right) / 2;
            //cout << "mid = " << mid << ", nums = " << nums[mid] << endl;
            //cout << left << " " << right << endl;  

            if (mid < nums.size() && target == nums[mid])
                return mid;
            if (left == right)
                return -1;
                
            if (nums[mid] > nums[right]) {
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};