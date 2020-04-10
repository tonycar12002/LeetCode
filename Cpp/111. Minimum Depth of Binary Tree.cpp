/*
Author: Tony Hsiao
Date: 2020/04/10
Topic: 111. Minimum Depth of Binary Tree
Speed: 12 ms, 17.6 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left)
            return 1 + minDepth(root->right);
        if (!root->right)
            return 1 + minDepth(root->left);
        return min(minDepth(root->right), minDepth(root->left)) + 1;
    }
};