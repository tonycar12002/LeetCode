/*
Author: Tony Hsiao
Date: 2021/05/09
Topic: 146. LRU Cache
Speed: 80 ms, 40 MB
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

struct Node {
  Node* next;
  Node* last;
  int key;
  int val;

  Node(): next(NULL), last(NULL) {};
  Node(int k, int v): key(k), val(v), next(NULL), last(NULL) {};
};

class LRUCache {
public:
  LRUCache(int capacity) {
    max_size_ = capacity;
    new_key_ = -1;
    old_key_ = -1;
  }

  void printAll(int key) {
    Node* tmp = caches_[key];
    while (tmp) {
      cout << tmp->key << " -> ";
      tmp = tmp->next;
    }
    cout << "\n---------------------\n";
  }

  void updateNode(int update_key) {
    if (caches_.size() == 1 || update_key == new_key_)
      return;
    if (caches_[update_key]->next)
      caches_[update_key]->next->last = caches_[update_key]->last;
    if (caches_[update_key]->last)
      caches_[update_key]->last->next = caches_[update_key]->next;

    if (update_key == old_key_)
      old_key_ = caches_[update_key]->next->key;
    caches_[new_key_]->next = caches_[update_key];
    caches_[update_key]->last = caches_[new_key_];
    caches_[update_key]->next = nullptr;
    new_key_ = update_key;
    // printAll(old_key_);
  }

  int get(int key) {
    // cout << "start get " << key << endl;
    if (caches_.find(key) == caches_.end()) {
      return -1;
    } else {
      updateNode(key);
      return caches_[key]->val;
    }
  }

  void put(int key, int value) {
    // cout << "start put " << key << endl;
    if (max_size_ == 0)
      return;
    if (caches_.find(key) != caches_.end()) {
      caches_[key]->val = value;
      updateNode(key);
      return;
    }

    if (caches_.size() == max_size_) {
      int tmp = old_key_;
      if (max_size_ == 1) {
        new_key_ = -1;
        old_key_ = -1;
      } else {
        old_key_ = caches_[old_key_]->next->key;
        caches_[old_key_]->last = nullptr;
      }
      delete caches_[tmp];
      // cout << "erase key " << tmp << endl;
      caches_.erase(tmp);
    }
    Node* new_node = new Node(key, value);
    if (new_key_ == -1) {
      old_key_ = key;
    } else {
      caches_[new_key_]->next = new_node;
      new_node->last = caches_[new_key_];
    }
    new_key_ = key;
    caches_[key] = new_node;
    // printAll(old_key_);
  }

private:
  std:: unordered_map<int, Node*> caches_;
  int max_size_;
  int new_key_;
  int old_key_;
};