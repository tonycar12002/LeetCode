/*
Author: Tony Hsiao
Date: 2021/05/23
Topic: 1110. Delete Nodes And Return Forest
Speed:  ms,  MB
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
  void findValidRoot() {

  }
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    std::unordered_set<int> delete_value;
    for (const auto& i : to_delete)
      delete_value.insert(i);

    vector<TreeNode*> ans;
    std::queue<TreeNode*> q;
    q.
    return ans;
  }
};