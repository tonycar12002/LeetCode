/*
Author: Tony Hsiao
Date: 2020/06/12
Topic: 326. Power of Three
Speed: 36 ms, 6.2 MB
Note:
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
    bool isPowerOfThree(int n) {
        return n && log10(n) / log10(3) == floor(log10(n) / log10(3));
    }
};