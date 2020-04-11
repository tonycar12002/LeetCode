/*
Author: Tony Hsiao
Date: 2020/04/11
Topic: 189. Rotate Array
Speed: 16 ms, 7.2 MB
Note: 先反轉0~k-1, 再反轉k~size-1，再反轉全部
[1,2,3,4,5,6,7]
5
1. [2 1 3 4 5 6 7]
2. [2 1 7 6 5 4 3]
3. [3 4 5 6 7 1 2]
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
    void reverse(vector<int>& nums, int start, int end) {
        while (start >=0 && end < nums.size() && start < end) {
            int tmp = nums[end];
            nums[end] = nums[start];
            nums[start] = tmp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0)
            return ;
        reverse(nums, 0, nums.size() - k - 1);
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }
};

