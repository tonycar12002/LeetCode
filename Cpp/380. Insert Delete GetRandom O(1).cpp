/*
Author: Tony Hsiao
Date: 2021/05/07
Topic: 380. Insert Delete GetRandom O(1)
Speed: 68 ms, 22.6 MB
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
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet() {

  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (random_set_.find(val) == random_set_.end()) {
      random_set_[val] = 1;
      return true;
    } else {
      return false;
    }
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (random_set_.find(val) == random_set_.end()) {
      return false;
    } else {
      random_set_.erase(val);
      return true;
    }
  }

  /** Get a random element from the set. */
  int getRandom() {
    auto it = random_set_.begin();
    std::advance(it, rand() % random_set_.size());
    return it->first;
  }

private:
  std::unordered_map<int, int> random_set_;
};

