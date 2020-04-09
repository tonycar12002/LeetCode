/*
Author: Tony Hsiao
Date: 2020/04/09
Topic: 83. Remove Duplicates from Sorted List
Speed: 8 ms, 7.7 MB
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* head_ = head;
        while (head) {
            // duplicates
            if (head->next && head->next->val == head->val)
                head->next = head->next->next;
            else
                head = head->next;
        }
        return head_;
    }
};