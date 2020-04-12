/*
Author: Tony Hsiao
Date: 2020/04/13
Topic: 232. Implement Queue using Stacks
Speed: 0 ms, 6.8 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;
class MyQueue {
public:
    stack<int> lists;
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> reverse; // origini stack sorted
        for (int i=0; !lists.empty(); ++i) {
            reverse.push(lists.top());
            lists.pop();
        }
        reverse.push(x);
        for (int i=0; !reverse.empty(); ++i) {
            lists.push(reverse.top());
            reverse.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int i = lists.top();
        lists.pop();
        return i;
    }
    
    /** Get the front element. */
    int peek() {
        return lists.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return lists.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */