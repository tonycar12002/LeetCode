/*
Author: Tony Hsiao
Date: 2020/04/10
Topic: 172. Factorial Trailing Zeroes
Speed: 0 ms, 6.1 MB
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
    int trailingZeroes(int n) {
        int five = 0;
        while (n>=5) {
            five += n / 5;
            n = n / 5;
        }
        return five;
    }
};