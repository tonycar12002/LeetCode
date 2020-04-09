/*
Author: Tony Hsiao
Date: 2020/04/09
Topic: 119. Pascal's Triangle II 
Speed: 4 ms, 6.5 MB
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
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        for (int y=0; y<=rowIndex; ++y) {
            vector<int> row;
            for (int x=0; x<y+1; ++x) {
                if (x == 0 || x == y)
                    row.push_back(1);
                else
                    row.push_back(ans[y-1][x-1] + ans[y-1][x]);
            }
            ans.push_back(row);
        }
        return ans[rowIndex];
    }
};
    
