/*
Author: Tony Hsiao
Date: 2020/06/06
Topic: 133. Clone Graph
Speed: 12 ms, 9 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    std::map<int, int> record;
    std::map<int, Node*> new_node_address;
    void clone(Node* node) {
        record[node->val] = 1;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            if (record[node->neighbors[i]->val]== 0) {
                Node* node_cp = new Node(node->neighbors[i]->val, node->neighbors[i]->neighbors);
                new_node_address[node->neighbors[i]->val] = node_cp;
                node->neighbors[i] = node_cp;
                clone(node_cp);
            }
            else {
                node->neighbors[i] = new_node_address[node->neighbors[i]->val];
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        Node* node_cp = new Node(node->val, node->neighbors);
        new_node_address[node_cp->val] = node_cp;
        clone(node_cp);
        return node_cp;
    }
};