/*
Author: Tony Hsiao
Date: 2021/05/15
Topic: 1025. Divisor Game
Speed: 0 ms, 5.8 MB
Note: Even will win
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
  bool divisorGame(int n) {
    return (n % 2) == 0;
  }
};