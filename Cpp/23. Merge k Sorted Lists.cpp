/*
Author: Tony Hsiao
Date: 2019/05/09
Topic: 23. Merge k Sorted Lists
Speed: 28 ms, 11.8 MB
Note: using map or priority queue to solve
*/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int>numbers;
        for(int i=0;i<lists.size();i++){
            ListNode* head = lists[i];
            while(head){
                numbers[head->first] += 1;
                head = head->next;
            }
        }

        ListNode* cur, *head = new ListNode(-1);
        cur = head;
        for(map<int, int>::iterator it = numbers.begin();it!=numbers.end();it++){
            while(it->second!=0){
                cur -> next = new ListNode(it->first);
                cur = cur->next;
                it->second --;
            }
            
        }
        return head->next;
    }
};