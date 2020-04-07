/*
Author: Tony Hsiao
Date: 2020/04/06
Topic: 40. Combination Sum II
Speed: 12 ms, 7 MB
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
    void FindCombination(vector<int>& candidates, vector<int>& current_ans, int target, int index) {
        if (index < candidates.size() && candidates[index] <= target) {
            int last_num ;
            for (int i=index; i<candidates.size(); ++i) {
                if (i != index && last_num == candidates[i])
                    continue;
                if (candidates[i] == target) {
                    current_ans.push_back(candidates[i]);
                    ans.push_back(current_ans);
                    current_ans.pop_back();
                }
                else if (candidates[i] > target) {
                    break;
                }
                else {
                    current_ans.push_back(candidates[i]);
                    FindCombination(candidates, current_ans, target - candidates[i], i+1);
                    current_ans.pop_back();
                }
                last_num = candidates[i];
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0)
            return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> current_ans;
        FindCombination(candidates, current_ans, target, 0);
        return  ans;
    }
};