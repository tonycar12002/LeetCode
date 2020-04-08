/*
Author: Tony Hsiao
Date: 2020/04/08
Topic: 1306. Jump Game III
Speed: 52 ms, 10.9 MB
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
    bool canReach(vector<int>& arr, int start) {
        if (start < 0 || start >= arr.size() || arr[start] == -1)
            return false;
        else if (arr[start] == 0)
             return true;
        else {
            int left = start - arr[start], right = start + arr[start];
            arr[start] = -1;
            return (canReach(arr, left) || canReach(arr, right));
        }
    }
};