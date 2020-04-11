/*
Author: Tony Hsiao
Date: 2020/04/11
Topic: 225. Implement Stack using Queues
Speed: 0 ms, 6.6 MB
Note: Idiot problem
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;
class MyStack {
public:
    std::queue<int> stack_;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stack_.push(x);
        for (int i=0; i<stack_.size()-1; ++i) {
            int val = stack_.front();
            stack_.push(val);
            stack_.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = stack_.front();
        stack_.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return stack_.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return stack_.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */