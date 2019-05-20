/*
Author: Tony Hsiao
Date: 2019/05/16
Topic: 210. Course Schedule II
Speed:
Note:
*/
class Solution {
private:
    vector<int>ans;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visted(numCourses, 0);
        vector<vector<int>>graph(prerequisites.size(), vector<int>(prerequisites[0].size, 0));

        for(int i=0;i<prerequisites.size();i++)
            graph[prerequisted[i][1]].push_back(prerequisted[i][0]);
        
        

        return ans;
    }
};