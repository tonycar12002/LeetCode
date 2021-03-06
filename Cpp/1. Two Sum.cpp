/*
Author: Tony Hsiao
Date: 2018/05/29
Topic: 1. Two Sum
Speed: 9 ms, 10.6MB
Note: 找陣列中兩數相加等於答案的數字，題目必唯一解 => 使用map library
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> numMap;
        for(int i =0;i<nums.size();i++)
            numMap[nums[i]] = i;
        for(int i =0;i<nums.size();i++)
        {
            int minus = target - nums[i];
            auto t = numMap.find(minus);
            //make sure don't use same elements
            if(t!=numMap.end() && i!=t->second)
            {
                ans.push_back(i);
                ans.push_back(t->second);
                return ans;
            }            
        }
        return ans;
    }    
};