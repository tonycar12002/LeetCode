/*
Author: Tony Hsiao
Date: 2020/04/01
Topic: 77. Combinations
Speed: 732 ms, 165.6 MB
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
    void DFS(vector<int>current_ans, int num, int k) {
        if (k == 0)
            ans.push_back(current_ans);
        else if (num > 0){
            for (int i=num; i>=1; --i) {
                current_ans.push_back(i);
                DFS(current_ans, i-1, k - 1);
                current_ans.pop_back();
            }
        }
        else;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        DFS(tmp, n, k);
        return ans;
    }
};