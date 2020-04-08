/*
Author: Tony Hsiao
Date: 2020/04/08
Topic: 45. Jump Game II
Speed:  ms,  MB
Note: 
1. TLE(Brute Force), Find the last element which can get current position, O(n^2)
2. O(n), Greedy 
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
    int min(int x, int y) {
        return (x<y) ? x : y;
    }
    int max(int x, int y) {
        return (x>y) ? x : y;
    }
    /*
    // Pass all tests but TLE 
    int jump(vector<int>& nums) {
        int current_position = nums.size() - 1;
        if (current_position <= 0)
            return 0;
        int steps = 0;
        while (current_position != 0) {
            for (int i=0; i<current_position; ++i) {
                if (nums[i] + i >= current_position) {
                    steps++;
                    current_position  = i ;
                }
            }
        }
        return steps;
    }
    */
   int jump(vector<int>& nums) {
        int target = nums.size() - 1, current_position = 0;
        if (target <= 0)
            return 0;
        int steps = 0;
        int i = 0;
        while (current_position < target) {
            steps++;
            int tmp = current_position;
            for (;i<=tmp ; ++i) {
                current_position = max(i+nums[i],current_position);
            }
        }
        return steps;
    }
};