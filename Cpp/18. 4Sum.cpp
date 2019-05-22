/*
Author: Tony Hsiao
Date: 2019/05/21
Topic: 18. 4Sum
Speed: 116 ms, 9.2 MB
Note:
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int last_i, last_j, last_k;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i != 0 && nums[last_i] == nums[i])
                continue;
            last_i = i;
            for(int j = i + 1 ; j < nums.size() ; j++){
                if(j != i + 1 && nums[last_j] == nums[j])
                    continue;
                last_j = j;
                for(int k = j + 1 ; k < nums.size() ; k++){
                    if(k != j + 1 && nums[last_k] == nums[k])
                        continue;
                    last_k = k;

                    int value = target - nums[i] - nums[j] - nums[k];
                    
                    if(value < nums[k])
                        break;
                    else if(binary_search(nums.begin() + k + 1, nums.end(), value))
                        ans.push_back({nums[i], nums[j], nums[k], value});
                }
            }
        }
        return ans;
    }
};