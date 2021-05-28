/*
Author: Tony Hsiao
Date: 2021/05/25
Topic: 729. My Calendar
Speed: 68 ms, 38.9 MB
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
class MyCalendar {
public:
  MyCalendar() {

  }

  bool book(int start, int end) {
    if (calendar_.size() == 0) {
      calendar_[{start, end}] = 1;
      return true;
    }
    auto it = calendar_.upper_bound({start, end});
    if (it != calendar_.end())
      if (end > it->first.first)
        return false;
    if (it != calendar_.begin()) {
      it--;
      if (it->first.second > start)
        return false;
    }
    calendar_[{start, end}] = 1;
    return true;
  }

private:
  std::map<std::pair<int, int>, int> calendar_;
};
