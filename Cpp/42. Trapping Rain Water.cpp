/*
Author: Tony Hsiao
Date: 2020/03/26
Topic: 42. Trapping Rain Water
Speed: 4 ms, 6.8 MB
Note: 兩個指標一左一右開始，兩個指標的數值夾的減去高度為蓄水量
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int min(int x, int y) {
        return (x>y) ? y : x;
    }
    int max(int x, int y) {
        return (x>y) ? x : y;
    }
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int ans = 0, min_elevation;
        while(left <= right) {
            int tmp = min(height[left], height[right]);
            min_elevation = max(tmp, min_elevation);
            if (min_elevation > height[right])
                ans +=  min_elevation - height[right];
            if (min_elevation > height[left])
                ans +=  min_elevation - height[left];
            if (height[left] >= height[right]) {
                right -= 1;
            }
            else {
                left += 1;
            }
        }
    }
};