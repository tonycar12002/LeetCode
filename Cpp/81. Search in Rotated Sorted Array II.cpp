/*
Author: Tony Hsiao
Date: 2020/03/26
Topic: 81. Search in Rotated Sorted Array II
Speed: 4 ms, 6.8 MB
Note: find the pivot first
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pivot = 0;
        vector<int>re_sort;
        for (int i = 1; i<nums.size(); ++i) {
          if (nums[i] < nums[i-1]) {
            pivot = i;
            break;
          }
        }
        re_sort.insert(re_sort.end(), nums.begin()+pivot, nums.end());
        re_sort.insert(re_sort.end(), nums.begin(), nums.begin()+pivot);
        /*for (auto i : re_sort){
          cout << i << " " ;
        }*/
        int left = 0, right = nums.size()-1, mid;
        while ( left <= right ) {
          mid = (left + right) / 2;
          if (re_sort[mid] == target)
            return true;
          else if (re_sort[mid] > target)
            right = mid - 1;
          else
            left = mid + 1;
        }
        return false;
    }
};