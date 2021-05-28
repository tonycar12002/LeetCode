/*
Author: Tony Hsiao
Date: 2021/05/23
Topic: 359. Logger Rate Limiter
Speed: 64 ms, 32.5 MB
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
class Logger {
public:
  /** Initialize your data structure here. */
  Logger() {

  }

  /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
      If this method returns false, the message will not be printed.
      The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    auto it = record_table_.find(message);
    if (it == record_table_.end()) {
      record_table_[message] = timestamp;
      return true;
    }
    if (timestamp - it->second < 10)
      return false;
    it->second = timestamp;
    return true;
  }

private:
  // <message, timestamp>
  std::map<std::string, int> record_table_;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */