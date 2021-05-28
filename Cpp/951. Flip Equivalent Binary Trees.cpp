/*
Author: Tony Hsiao
Date: 2021/05/25
Topic: 951. Flip Equivalent Binary Trees
Speed: 4 ms, 12.2 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)
      return true;
    else if ((root1 && !root2) || (root2 && !root1))
      return false;
    else if (root1->val != root2->val)
      return false;
    return (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)) ||
           (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right));
  }
};