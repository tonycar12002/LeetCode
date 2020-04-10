/*
Author: Tony Hsiao
Date: 2020/04/10
Topic: 160. Intersection of Two Linked Lists
Speed: 108 ms, 21 MB
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> A_table;
        while (headA) {
            A_table [headA] = 1;
            headA = headA -> next;
        }
        while (headB) {
            if (A_table[headB] == 1)
                return headB;
            headB = headB -> next;
        }
        return NULL;
    }
};