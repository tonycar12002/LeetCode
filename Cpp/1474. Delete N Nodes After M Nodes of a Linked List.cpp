/*
Author: Tony Hsiao
Date: 2021/06/10
Topic: 1474. Delete N Nodes After M Nodes of a Linked List
Speed:  ms,  MB
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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if (!head)
            return nullptr;
        int counter = 0;
        ListNode* tmp = head;
        while (tmp) {
            counter++;
            if (counter == m) {
                int delete_num = 0;
                ListNode* cur = tmp;
                tmp = tmp->next;
                while (delete_num++ < n ) {
                    if (!tmp) {
                        cur ->next = nullptr;
                        return head;
                    }
                    ListNode* need_delete = tmp;
                    tmp = tmp->next;
                    delete need_delete;
                }
                cur->next = tmp;
                tmp = cur;
                counter = 0;
            }
            tmp = tmp->next;
        }
        return head;
    }
};
