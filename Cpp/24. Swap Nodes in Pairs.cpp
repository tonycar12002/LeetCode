/*
Author: Tony Hsiao
Date: 2020/03/31
Topic: 24. Swap Nodes in Pairs
Speed: 0 ms, 6.8 MB
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* head_cp = head, *root = head;
        bool first_time = true;
        while (head) {
            if (head -> next) {
                ListNode* tmp = head -> next;
                head -> next = head -> next -> next;
                tmp -> next = head;
                if (first_time) {
                    first_time = false;
                    head_cp = tmp;
                }
                else
                    root -> next = tmp;
                root = head;
            }
            head = head -> next;
        } 
        return head_cp;
    }
};