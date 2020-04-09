/*
Author: Tony Hsiao
Date: 2020/04/09
Topic: 107. Binary Tree Level Order Traversal II
Speed: 4 ms, 11.8 MB
Note: BFS(level order), use queue to implement, http://alrightchiu.github.io/SecondRound/binary-tree-traversalxun-fang.html#pre
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> level_order;
        vector<vector<int>> level_order_inverse;
        if (!root)
            return level_order;
        
        queue <pair<TreeNode*, int>> traversal_queue;
        traversal_queue.push(pair<TreeNode*, int>(root, 0));

        while (!traversal_queue.empty()) {
            // number, level
            pair<TreeNode*, int> node_info = traversal_queue.front();
            traversal_queue.pop();

            if (level_order.size() <= node_info.second) {
                vector<int> tmp;
                level_order.push_back(tmp);
            }
            level_order[node_info.second].push_back(node_info.first->val);
            if (node_info.first->left) {
                traversal_queue.push(pair<TreeNode*, int>(node_info.first->left, node_info.second + 1));
            }
            if (node_info.first->right) {
                traversal_queue.push(pair<TreeNode*, int>(node_info.first->right, node_info.second + 1));
            }
        }
        for(int i=level_order.size()-1; i>=0; --i) {
            level_order_inverse.push_back(level_order[i]);
        }
        return level_order_inverse;
    }
};