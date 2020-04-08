/*
Author: Tony Hsiao
Date: 2020/04/08
Topic: 56. Merge Intervals
Speed: 24 ms, 9.9 MB
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [](const std::vector<int> &a, const std::vector<int> &b) {
              return a[0] < b[0];
          });
            
        vector<vector<int>> ans;
        for (int i=0; i<intervals.size(); ++i) {
            if (i != 0) {
                if (intervals[i][0] > ans[ans.size()-1][1]) {
                    ans.push_back(intervals[i]);
                }
                else {
                    int max_val = max(ans[ans.size()-1][1], intervals[i][1]);
                    ans[ans.size()-1][1] = max_val;
                }
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
    
        return ans;
    }
};