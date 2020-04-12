/*
Author: Tony Hsiao
Date: 2020/04/13
Topic: 231. Power of Two
Speed: 0 ms, 5.9 MB
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
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        while (n > 1) {
            if (n % 2 != 0)
                return false;
            n /= 2;
        }
        return true;
    }
};