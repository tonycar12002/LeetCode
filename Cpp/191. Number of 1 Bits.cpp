/*
Author: Tony Hsiao
Date: 2020/04/11
Topic: 191. Number of 1 Bits
Speed: 0 ms, 6.2 MB
Note: Hamming Weights
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;    
        for (int i=0; i<32; ++i) {
          ans += (n & 1); // get the last digits of n
          n = n >> 1; // pop last digits
        }
        return ans;
    }
};