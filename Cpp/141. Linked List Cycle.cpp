/*
Author: Tony Hsiao
Date: 2020/04/10
Topic: 141. Linked List Cycle
Speed:  ms,  MB
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
    bool hasCycle(ListNode *head) {
        set<ListNode*> record;
        while (head) {
            if (record.find(head) == record.end()) {
                record.insert(head);
                head = head->next;
            }
            else
                return true;
        }
        return false;
    }
};