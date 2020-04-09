/*
Author: Tony Hsiao
Date: 2020/04/09
Topic: 118. Pascal's Triangle
Speed: 0 ms, 6.6 MB
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int y=0; y<numRows; ++y) {
            vector<int> row;
            for (int x=0; x<y+1; ++x) {
                if (x == 0 || x == y)
                    row.push_back(1);
                else
                    row.push_back(ans[y-1][x-1] + ans[y-1][x]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};