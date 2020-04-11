/*
Author: Tony Hsiao
Date: 2020/04/11
Topic: 190. Reverse Bits
Speed: 0 ms, 5.9 MB
Note: Same as problem 191
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
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for (int i=0; i<32; ++i) {
            if ((n & 1) == 1)
                ans += 1;
            if (i != 31)
                ans = ans << 1;
            n = n >> 1;
        }
        return ans;
    }
};