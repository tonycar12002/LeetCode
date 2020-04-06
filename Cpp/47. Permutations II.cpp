/*
Author: Tony Hsiao
Date: 2020/04/06
Topic: 47. Permutations II
Speed: 44 ms, 8.2 MB
Note: 排序後加一個變數確認是否連續一樣的數字，一樣的數字就不用遞迴
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
    void DFS(vector<int>& nums, vector<int>& current_ans, vector<int>& visted) {
        if (current_ans.size() == nums.size()) {
            ans.push_back(current_ans);
        }
        else {
            int last_element;
            for (int i=0; i<nums.size(); ++i) {
                if ((i !=0 && last_element == nums[i]) || visted[i] == 1)
                    continue;
                else {
                    visted[i] = 1;
                    current_ans.push_back(nums[i]);
                    DFS(nums, current_ans, visted);
                    current_ans.pop_back();
                    visted[i] = 0;
                    last_element = nums[i];
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>visted(nums.size(), 0);
        sort(nums.begin(), nums.end(), greater<int>()); 
        vector<int> current_ans;
        DFS(nums, current_ans, visted);
        return ans;
    }
};