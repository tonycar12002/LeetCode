/*
Author: Tony Hsiao
Date: 2021/05/10
Topic: 86. Partition List
Speed: 8 ms, 10.4 MB
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
  ListNode* partition(ListNode* head, int x) {
    ListNode* tmp = head;
    ListNode* first_part_head = new ListNode(-1);
    ListNode* tmp_first = first_part_head;
    ListNode* second_part_head = new ListNode(-1);
    ListNode* tmp_second = second_part_head;

    while(tmp) {
      if (tmp->val < x) {
        tmp_first->next = new ListNode(tmp->val);
        tmp_first = tmp_first->next;
      } else {
        tmp_second->next = new ListNode(tmp->val);
        tmp_second = tmp_second->next;
      }
      tmp = tmp->next;
    }
    tmp_first->next = second_part_head->next;
    delete second_part_head;
    return first_part_head->next;
  }
};
