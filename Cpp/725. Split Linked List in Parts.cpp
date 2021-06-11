/*
Author: Tony Hsiao
Date: 2021/06/11
Topic: 725. Split Linked List in Parts
Speed: 8 ms, 8.9 MB
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* tmp = root;
        int length = 0;
        while (tmp) {
            length++;
            tmp = tmp->next;
        }
        tmp = root;
        if (k > length) {
            std::vector<ListNode*> ans(k, nullptr);
            for (int i = 0; i < length; ++i) {
                ans[i] = tmp;
                ListNode* cur = tmp;
                tmp = tmp->next;
                cur->next = nullptr;
            }
            return ans;
        } else {
            std::vector<ListNode*> ans;
            int mod = length % k;
            int divide = length / k;
            for (int i = 0; i < k; ++i) {
                int expand = 0;
                if (i < mod)
                    expand = 1;
                ListNode* new_head = tmp;
                ans.emplace_back(new_head);
                ListNode* cur = new_head;
                tmp = tmp->next;
                for (int j = 1; j < divide + expand; ++j) {
                    cur->next = tmp;
                    tmp = tmp->next;
                    cur = cur->next;
                }
                cur->next = nullptr;
            }
            return ans;
        } // end if
    }
};
