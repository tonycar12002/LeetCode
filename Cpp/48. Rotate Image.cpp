/*
Author: Tony Hsiao
Date: 2020/04/06s
Topic: 48. Rotate Image
Speed: 12 ms, 7 MB
Note: https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        // reverse
        for (int y=0; y<n/2; ++y) {
            for (int x=0; x<n; ++x) {
                swap(matrix[y][x], matrix[n-y-1][x]);
            }
        }
        // symmetry
        for (int y=0; y<n; ++y) {
            for (int x=0; x<=y; ++x) {
                swap(matrix[y][x], matrix[x][y]);
            }
        }
    }
};