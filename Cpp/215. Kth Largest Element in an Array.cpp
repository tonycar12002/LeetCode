/*
Author: Tony Hsiao
Date: 2019/05/15
Topic: 215. Kth Largest Element in an Array
Speed: 16 ms, 9.2 MB
Note:
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), std::greater<>());
        return nums[k-1];
    }
};