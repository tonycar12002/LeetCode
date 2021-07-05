/*
Author: Tony Hsiao
Date: 2021/05/28
Topic: 509. Fibonacci Number
Speed: 12 ms, 5.7 MB
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
class Solution {
public:
  int fib(int n) {
    if (n <= 0)
      return 0;
    else if (n == 1)
      return 1;
    return fib(n - 1) + fib(n - 2);
  }
};