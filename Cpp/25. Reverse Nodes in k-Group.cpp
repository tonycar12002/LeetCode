/*
Author: Tony Hsiao
Date: 2020/03/31
Topic: 25. Reverse Nodes in k-Group
Speed: 28 ms, 9.1 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* head_cp = head, *last_end_node = head;
        bool first_time = true;
        while (head) {
            int left_num = 0;
            ListNode* tmp = head;
            while (tmp && left_num < k) { // left nodes need >= k 
                tmp = tmp -> next;
                left_num++;
            }
            if (left_num != k)
                break;
            else {
                left_num = 0;
                ListNode* start = head;
                ListNode* last = head;
                for (int i=1 ; i<k; ++i) {
                    tmp = start -> next;
                    start -> next = start -> next -> next;
                    tmp -> next = last;
                    last = tmp;
                }
                if (first_time) {
                    first_time = false;
                    head_cp = last;
                }
                else
                    last_end_node -> next = last;
                last_end_node = head;
                head = start -> next;
            }
        }
        return head_cp;
    }
};