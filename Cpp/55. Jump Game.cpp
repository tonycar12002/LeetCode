/*
Author: Tony Hsiao
Date: 2020/04/08
Topic: 55. Jump Game
Speed: 8 ms, 7.9 MB
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
    bool canJump(vector<int>& nums) {
        int max_steps = 0;
        for (int i=0; i<nums.size()-1; ++i) {
            //cout << max_steps << endl;
            if (max_steps >= nums.size()-1 || max_steps < i)
                break;
            else
                 max_steps = max(max_steps, i+nums[i]);
        }
        if (max_steps >= nums.size()-1)
            return true;
        else
            return false;
    }
};