/*
Author: Tony Hsiao
Date: 2020/04/13
Topic: 237. Delete Node in a Linked List
Speed: 16 ms, 8 MB
Note: 毫無意義的一題
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next; 
    }
};