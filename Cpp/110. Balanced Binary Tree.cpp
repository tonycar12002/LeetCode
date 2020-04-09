/*
Author: Tony Hsiao
Date: 2020/04/09
Topic: 110. Balanced Binary Tree
Speed: 16 ms, 14.4 MB
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
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        //cout << left << " " << right << endl;
        if (abs(left - right) > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
};