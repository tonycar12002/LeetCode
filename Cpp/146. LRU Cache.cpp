/*
Author: Tony Hsiao
Date: 2021/04/21
Topic: 146. LRU Cache
Speed:  ms,  MB
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
class LRUCache {
public:
  LRUCache(int capacity) {
    current_capacity_ = 0;
    capacity_ = capacity;
  }

  int get(int key) {
  }

  void put(int key, int value) {

  }

private:
  int last_key_;
  int current_capacity_;
  int capacity_
  std::unordered_map<int, int> cache_;
  int key_[3001];
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */