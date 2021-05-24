/*
Author: Tony Hsiao
Date: 2021/05/10
Topic: 251. Flatten 2D Vector.cpp
Speed: 16 ms, 19.6 MB
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
class Vector2D {
public:
  Vector2D(vector<vector<int>>& vec) {
    vec_ = vec;
  }

  int next() {
    while (true) {
      if (index_2d_ >= vec_.size())
        return -1;
      if (index_1d_ == vec_[index_2d_].size()) {
        index_2d_++;
        index_1d_ = 0;
        continue;
      }
      return vec_[index_2d_][index_1d_++];
    }
  }

  bool hasNext() {
    int tmp_1d = index_1d_;
    int tmp_2d = index_2d_;
    while (true) {
      if (tmp_2d >= vec_.size())
        return false;
      if (tmp_1d == vec_[tmp_2d].size()) {
        tmp_2d++;
        tmp_1d = 0;
        continue;
      }
      break;
    }
    return true;
  }

private:
  std::vector<std::vector<int>> vec_;
  int index_1d_ = 0;
  int index_2d_ = 0;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */