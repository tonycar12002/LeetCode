/*
Author: Tony Hsiao
Date: 2019/05/22
Topic: 99. Recover Binary Search Tree
Speed: 24 ms, 23.8 MB
Note:
Tree In-Order Traverse
*/
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
private:
    int counter = 0;
    vector<int>sequence;
    vector<TreeNode*>node_swap;
public:
    void InOrderTraverse(TreeNode* current, vector<int>change){
        if(!current)
            return void();
        
        InOrderTraverse(current->left, change);
        sequence.push_back(current->val);
        
        if(node_swap.size() == 2)
            return void();
        if(change.size() != 0 && change[node_swap.size()] == counter)
            node_swap.push_back(current);
 
        counter += 1;
        InOrderTraverse(current->right, change);
    }
    void recoverTree(TreeNode* root) {
        vector<int>change;
        InOrderTraverse(root, change);
        
        // find the target tree node
        for(int i=1;i<sequence.size();i++)
            if(sequence[i] < sequence[i-1])
                (change.size() == 0 ) ? change.push_back(i-1) : change.push_back(i);
        if(change.size() == 1)
            change.push_back(change[0]+1);

        //cout << "Change = " << change[0] << " " << change[1] << endl;
        counter = 0 ;
        InOrderTraverse(root, change);

        //cout << "node_swap size = " << node_swap.size() << endl;
        
        // swap the node
        int tmp_val;
        tmp_val = node_swap[0] -> val;

        node_swap[0]->val = node_swap[1]->val;
        node_swap[1]->val = tmp_val;
        
    }
};