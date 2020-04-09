/*
Author: Tony Hsiao
Date: 2020/04/09
Topic: 108. Convert Sorted Array to Binary Search Tree
Speed: 24 ms, 21.8 MB
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
    void BuildBSTTree(TreeNode* root, vector<int>& nums, int left, int right) {
        if (left <= right) {
            int mid = (left + right) / 2;
            root->val = nums[mid];
            if (mid - 1 >= left) {
                root->left = new TreeNode(0);
                BuildBSTTree(root->left, nums, left, mid - 1);
            }
            if (mid + 1 <= right) {
                root->right = new TreeNode(0);
                BuildBSTTree(root->right, nums, mid + 1, right);
            }
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        TreeNode* head = new TreeNode(0);
        BuildBSTTree(head, nums, 0, nums.size() - 1);
        return head;
    }
};
