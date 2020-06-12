/*
Author: Tony Hsiao
Date: 2020/06/12
Topic: 179. Largest Number
Speed: 12 ms, 11 MB
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
    static bool compare(int a, int b) {
        std::string first = std::to_string(a);
        std::string second = std::to_string(b);
        return first + second > second + first;
    }
    string largestNumber(vector<int>& nums) {
        bool all_zeros = true;
        for (auto num : nums) {
            if (num != 0) {
                all_zeros = false;
                break;
            }
        }
        if (all_zeros)
            return "0";
        sort(nums.begin(), nums.end(), compare);
        string ans = "";
        for (auto num : nums)
            ans += std::to_string(num);
        return ans;
    }
};