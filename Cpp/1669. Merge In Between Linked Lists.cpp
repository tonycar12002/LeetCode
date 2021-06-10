/*
Author: Tony Hsiao
Date: 2021/06/10
Topic: 1669. Merge In Between Linked Lists
Speed: 504 ms, 95.1 MB
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tmp = list1;
        int c = a;
        while (c - 1 > 0) {
            c--;
            tmp = tmp->next;
        }
        ListNode* cur = tmp;
        int num = b - a;
        tmp = tmp->next;
        while (num-- >= 0) {
            ListNode* need_d = tmp;
            tmp = tmp->next;
            delete need_d;
        }
        cur->next = list2;
        while  (list2->next) {
            list2 = list2->next;
        }
        list2->next = tmp;
        return list1;
    }
};
