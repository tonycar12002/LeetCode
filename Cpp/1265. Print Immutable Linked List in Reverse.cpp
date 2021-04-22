/*
Author: Tony Hsiao
Date: 2021/03/28
Topic: 1265. Print Immutable Linked List in Reverse
Speed: 4 ms, 6.7 MB
Note: 簡單暴力就用stack存一下，此外特別思路利用遞迴(https://leetcode.com/problems/print-immutable-linked-list-in-reverse/submissions/)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
  void printLinkedListInReverse(ImmutableListNode* head) {
    if (!head)
      return;
    printLinkedListInReverse(head->getNext());
    head->printValue();
  }
};