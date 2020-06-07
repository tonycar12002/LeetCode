/*
Author: Tony Hsiao
Date: 2020/06/06
Topic: 96. Unique Binary Search Trees
Speed: 0 ms, 6.3 MB
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
    int numTrees(int n) {
        if (n == 1)
            return 1;
        if (n == 0)
            return 0;
        n += 1;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i] += dp[i - j] * dp[j];
            }
        }
        return dp[n];
    }
};