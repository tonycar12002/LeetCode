/*
Author: Tony Hsiao
Date: 2020/04/13
Topic: 234. Palindrome Linked List
Speed: 28 ms, 11.4 MB
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
    bool isPalindrome(ListNode* head) {
        queue<int> normal;
        stack<int> reverse;
        while (head) {
            normal.push(head->val);
            reverse.push(head->val);
            head = head -> next;
        }
        while (!normal.empty()) {
            if (normal.front() != reverse.top())
                return false;
            normal.pop();
            reverse.pop();
        }
        return true;
    }
};