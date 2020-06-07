/*
Author: Tony Hsiao
Date: 2020/06/07
Topic: 103. Binary Tree Zigzag Level Order Traversal
Speed: 4 ms, 13.2 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> ans;
    void preOrder(TreeNode* root, int layer) {
        if (root == nullptr)
            return;
        if (layer >= ans.size())
            ans.push_back(vector<int>());
        preOrder(root->left, layer + 1);
        preOrder(root->right, layer + 1);   
        ans[layer].push_back(root->val);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return ans;
        preOrder(root, 0);
        for (int i = 1; i < ans.size(); i += 2) {
            std::reverse(ans[i].begin(), ans[i].end());
        }
            
        return ans;
    }
};