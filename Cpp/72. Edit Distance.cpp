/*
Author: Tony Hsiao
Date: 2019/11/20
Topic: 72. Edit Distance
Speed: 16 ms, 11.4 MB
Note: Levenshtein distance
https://zh.wikipedia.org/wiki/萊文斯坦距離

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    std::vector<vector<int>> distance_table(word1.size()+1, vector<int>(word2.size()+1, 0));
    // create longest Levenshtein table
    for (int y=0; y<=word1.size(); ++y)
      distance_table[y][0] = y;
    for (int x=0; x<=word2.size(); ++x)
      distance_table[0][x] = x;

    for (int y=1; y<=word1.size(); ++y) {
      for (int x=1; x<=word2.size(); ++x) {
        int add = 1;
        if (word1[y-1] == word2[x-1]) 
          add = 0;
        distance_table[y][x] = 
            std::min(distance_table[y-1][x-1] + add, distance_table[y-1][x] + 1);
        distance_table[y][x] = 
            std::min(distance_table[y][x], distance_table[y][x-1] + 1);
      }
    } // end for

    return distance_table[word1.size()][word2.size()];
  }
};