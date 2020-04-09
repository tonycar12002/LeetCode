/*
Author: Tony Hsiao
Date: 2020/04/09
Topic: 104. Maximum Depth of Binary Tree
Speed: 8 ms, 17.1 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
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
public:
    int max(int x, int y) {
        return (x>y) ? x : y;
    }
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        else if (!root->left && !root->right)
            return 1;
        else
            return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};