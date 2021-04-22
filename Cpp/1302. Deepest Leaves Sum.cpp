/*
Author: Tony Hsiao
Date: 2021/03/29
Topic: 1302. Deepest Leaves Sum
Speed: 44 ms, 39.3 MB
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int deepestLeavesSum(TreeNode* root, int level = 0) {
    std::queue<std::pair<TreeNode*, int>> q;
    if (!root)
      return 0;
    q.push(std::pair<TreeNode*, int>(root, 0));
    int deep_level = 0;
    int sum = 0;
    while (q.empty() == false) {
      std::pair<TreeNode*, int> tmp = q.front();
      q.pop();
      TreeNode* node = tmp.first;
      int level = tmp.second;
      if (node->left)
        q.push(std::pair<TreeNode*, int>(node->left, level + 1));
      if (node->right)
        q.push(std::pair<TreeNode*, int>(node->right, level + 1));
      if (level < deep_level)
        continue;
      if (level > deep_level) {
        deep_level = level;
        sum = 0;
      }
      sum += node->val;
    }
    return sum;
  }
};