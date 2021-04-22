/*
Author: Tony Hsiao
Date: 2021/03/31
Topic: 95. Unique Binary Search Trees II
Speed:  ms,  MB
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
  void createBinaryTree(TreeNode* node, std::vector<int> visted) {

  }
  vector<TreeNode*> generateTrees(int n) {
    std::vector<int> visted(n, 0);
    for (int i = 1; i <= n; ++i) {

    }
  }
};