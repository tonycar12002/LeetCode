/*
Author: Tony Hsiao
Date: 2020/04/08
Topic: 797. All Paths From Source to Target
Speed: 84 ms, 11.4 MB
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
    vector<vector<int>> ans;
    void DFS(vector<vector<int>>& graph, int cur_node, vector<int>& visted, 
            vector<int>& cur_path) {
        cur_path.push_back(cur_node);
        //cout << &cur_path << endl;
        if (cur_node == graph.size()-1)
            ans.push_back(cur_path);
        for (int i=0; i<graph[cur_node].size(); ++i) {
            int next_node = graph[cur_node][i];
            if (visted[next_node] == 0) { 
                visted[next_node] = 1;
                DFS(graph, next_node, visted, cur_path);
                visted[next_node] = 0;
            }
        }
        // call by reference, cur_path will use same address, we need to delete add element
        cur_path.pop_back(); 
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> visted(graph.size(), 0);
        vector<int> cur_path;
        DFS(graph, 0, visted, cur_path);
        return ans;
    }
};