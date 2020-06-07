/*
Author: Tony Hsiao
Date: 2020/06/07
Topic: 147. Insertion Sort List
Speed: 32 ms, 9.7 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        ListNode* head_now = head;
        ListNode* pre_node = head;
        head = head->next;
        while(head) {
            if (head->val < pre_node->val) {
                ListNode* tmp_now = head_now;
                ListNode* tmp_prev = head_now;
                while (tmp_now != NULL) {
                    if (tmp_now->val > head->val) {
                        pre_node->next = head->next;
                        head->next = tmp_now;
                        if (tmp_now == tmp_prev) {
                            head_now = head;
                        }
                        else {
                            tmp_prev->next = head;
                        }
                        head = pre_node->next;
                        break;
                    }
                    tmp_prev = tmp_now;
                    tmp_now = tmp_now->next;
                }
            }
            else {
                pre_node = head;
                head = head->next;
            }
        }
        return head_now;
    }
};