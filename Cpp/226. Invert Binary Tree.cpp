/*
Author: Tony Hsiao
Date: 2019/05/22
Topic: 226. Invert Binary Tree
Speed: 4 ms, 9.1 MB
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
public:
    void InvertBinaryTree(TreeNode* root){
        if(!root)
            return void();
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        InvertBinaryTree(root->left);
        InvertBinaryTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        InvertBinaryTree(root);
        return root;
    }
};