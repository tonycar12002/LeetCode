/*
Author: Tony Hsiao
Date: 2020/04/03
Topic: 46. Permutations
Speed: 8 ms, 7.3 MB
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
    vector<vector<int>> ans;
    void DFS(vector<int>& nums, vector<int>& current_ans, map<int, int>& record) {
        if (current_ans.size() == nums.size()) {
            ans.push_back(current_ans);
        }
        else {
            for(int i=0; i<nums.size(); i++) {
                if (record[nums[i]] == 0) {
                    record[nums[i]] = 1;
                    current_ans.push_back(nums[i]);
                    DFS(nums, current_ans, record);
                    current_ans.pop_back();
                    record[nums[i]] = 0;
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        map<int, int> record;
        for(int i=0; i<nums.size(); i++) 
            record[nums[i]] = 0;
        DFS(nums, tmp, record);
        return ans;
    }
};