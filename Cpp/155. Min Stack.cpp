/*
Author: Tony Hsiao
Date: 2020/04/13
Topic: 155. Min Stack
Speed: 40 ms, 14.7 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;
struct Node {
    int  val;
    Node* pre;
    Node(int v):val(v), pre(NULL){}
};
class MinStack {
public:
    /** initialize your data structure here. */
    Node* now;
    int min_val = INT_MAX;
    MinStack() {
        now = new Node(INT_MAX);
    }
    
    void push(int x) {
        Node* new_node = new Node(x);
        new_node -> pre = now;
        now = new_node;
        min_val = min(min_val, x);
    }
    
    void pop() {
        Node* tmp;
        if (min_val == now->val) {
            tmp = now -> pre;
            min_val = INT_MAX;
            while (tmp) {
                min_val = min(min_val, tmp->val);
                tmp = tmp -> pre;
            }
        }
        tmp = now;
        if (now->pre) {
            now = now -> pre;
            delete tmp;
        }
    }
    
    int top() {
        return now->val;
    }
    
    int getMin() {
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */