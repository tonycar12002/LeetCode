/*
Author: Tony Hsiao
Date: 2021/06/11
Topic: 1019. Next Greater Node In Linked List
Speed: 436 ms, 83.8 MB
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
    vector<int> nextLargerNodes(ListNode* head) {
        std::vector<int> ans;
        // index and value
        int index = 0;
        std::map<int, std::vector<int>> record;
        while (head) {
            for (auto [value, index_vec] : record) {
                if (value >= head->val) {
                    break; 
                } else {
                    for (const auto& i : index_vec)
                        ans[i] = head->val;
                    record.erase(value);
                }
            }
            record[head->val].emplace_back(index);
            ans.emplace_back(0);
            index++;
            head = head->next;
        }
        return ans;
    }
};
