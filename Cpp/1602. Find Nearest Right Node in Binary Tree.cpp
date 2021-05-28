/*
Author: Tony Hsiao
Date: 2021/05/23
Topic: 1602. Find Nearest Right Node in Binary Tree
Speed: 144 ms, 87.2 MB
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
  TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    if (!root)
      return nullptr;
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root, 0});
    int find_level = -1;
    while(!q.empty()) {
      auto current_node = q.front();
      q.pop();
      if (find_level != -1) {
        if (current_node.second == find_level)
          return current_node.first;
        else
          return nullptr;
      }
      if (current_node.first->val == u->val) {
        find_level = current_node.second;
      }
      if (current_node.first->left)
        q.push({current_node.first->left, current_node.second + 1});
      if (current_node.first->right)
        q.push({current_node.first->right, current_node.second + 1});
    }
    return nullptr;
  }
};