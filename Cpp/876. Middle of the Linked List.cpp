/*
Author: Tony Hsiao
Date: 2021/05/28
Topic: 876. Middle of the Linked List
Speed: 0 ms, 6.5 MB
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
  ListNode* middleNode(ListNode* head) {
    if (!head)
      return nullptr;
    if (!head->next)
      return head;
    ListNode* first = head;
    ListNode* second = head->next;
    while (second->next) {
      if (!(second->next->next)) {
        break;
      }
      first = first->next;
      second = second->next->next;
    }
    return first->next;
  }
};