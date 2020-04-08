/*
Author: Tony Hsiao
Date: 2020/04/08
Topic: 983. Minimum Cost For Tickets
Speed: 4 ms, 6.7 MB
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
    int min(int x, int y) {
        return (x>y) ? y : x;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> min_ticket(366, INT_MAX); // 0 - 365
        vector<int> days_ticket{1, 7, 30};
        min_ticket[0] = 0;
        int counter = 0;
        for (int i=1; i<=days[days.size()-1];++i) {
            bool flag = false;
            for (int j=0; j<costs.size(); ++j) {
                if (i == days[counter]) { // travel day
                    if (days_ticket[j] <= i)
                        min_ticket[i] = min(min_ticket[i-days_ticket[j]] + costs[j], min_ticket[i]);
                    else
                        min_ticket[i] = min(min_ticket[0] + costs[j], min_ticket[i]);
                    flag = true;
                }
                else
                    min_ticket[i] = min_ticket[i-1];
            }
            if (flag)
                counter++;
            //cout << i << " " << min_ticket[i] << endl;
        }
        return min_ticket[days[days.size()-1]];
    }
};