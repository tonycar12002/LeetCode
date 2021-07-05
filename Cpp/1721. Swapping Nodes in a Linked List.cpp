/*
Author: Tony Hsiao
Date: 2021/06/10
Topic: 1721. Swapping Nodes in a Linked List
Speed: 768 ms, 180.1 MB
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start_node;
        ListNode* end_node = nullptr;
        ListNode* current_node = head;
        int index = 0;
        while (current_node) {
            index++;
            if (index == k) {
                start_node = current_node;
                end_node = head;
            }
            if (!current_node->next)
                break;
            if (end_node)
                end_node = end_node->next;
            current_node = current_node->next;
        }
        swap(end_node->val, start_node->val);
        return head;
    }
};
