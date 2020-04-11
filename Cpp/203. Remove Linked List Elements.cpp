/*
Author: Tony Hsiao
Date: 2020/04/11
Topic: 203. Remove Linked List Elements
Speed: 32 ms, 10.8 MB
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head = head;
        while (head) {
            if (head->next && head->next->val == val)
                head -> next = head -> next -> next;
            else
                head = head -> next;
        }
        while (new_head) {
            if (new_head->val != val)
                break;
            new_head = new_head->next;
        }
        return new_head;
    }
};

