/*
Author: Tony Hsiao
Date: 2019/11/20
Topic: 112. Path Sum
Speed: 16 ms, 19.7 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>

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
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        sum -= root->val;
        if (sum == 0 && !root->left && !root->right)
            return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};