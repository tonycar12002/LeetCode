/*
Author: Tony Hsiao
Date: 2019/05/15
Topic: 965. Univalued Binary Tree
Speed: 4 ms, 10.7MB
Note:
*/
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
    int value = INT_MAX;
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return true;
        if(value != INT_MAX && value != root->val)
            return false;
        

        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};