/*
Author: Tony Hsiao
Date: 2019/11/20
Topic: 113. Path Sum II
Speed: 24 ms, 38.1 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<int>>ans;
public:
    void DFS(vector<int>solution, TreeNode* root, int sum) {
        if (!root)
            return void();
        sum -= root->val;
        solution.push_back(root->val);
        if (sum == 0 && !root->left && !root->right) {
            ans.push_back(solution);
            return void();
        }
        DFS(solution, root->left, sum);
        DFS(solution, root->right, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        DFS(tmp, root, sum);
        return ans;
    }
};