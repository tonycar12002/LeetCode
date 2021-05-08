/*
Author: Tony Hsiao
Date: 2021/05/08
Topic: 129. Sum Root to Leaf Numbers
Speed: 0 ms, 9.1 MB
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
class Solution {
public:
  int sumNumbers(TreeNode* root, int nums = 0) {
    nums = nums * 10 + root->val;
     if (root->left && root->right) {
       return sumNumbers(root->left, nums) + sumNumbers(root->right, nums);
     } else if (root->left) {
       return sumNumbers(root->left, nums);
     } else if (root->right) {
       return sumNumbers(root->right, nums);
     }
     return nums;
  }
};
