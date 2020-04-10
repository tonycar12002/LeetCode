/*
Author: Tony Hsiao
Date: 2020/04/10
Topic:  121. Best Time to Buy and Sell Stock
Speed: 4 ms, 7.3 MB
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
    int maxProfit(vector<int>& prices) {
        int max_val = INT_MAX;
        int profit = 0;
        for (int i=prices.size()-1; i>=0; --i) {
            if (max_val == INT_MAX)
                max_val = prices[i];
            else if (max_val > prices[i])
                profit = max(profit, max_val - prices[i]);
            else
                max_val = prices[i];
        }
        return profit;
    }
};