/*
Author: Tony Hsiao
Date: 2019/05/10
Topic: 128. Longest Consecutive Sequence
Speed:
Note:
1. Check the neighborhood of target
2. Find the root of exist neighborhood
3. Update the union and amount

*/
class Solution {
private:
    Struct Node{
        Node():root(INT_MAX), amount(0){}
        int root;
        int amount;
    }
public:
    int max(int x, int y){
        return (x>y) ? x : y;
    }
    int longestConsecutive(vector<int>& nums) {
        map<int, Node>root_table; //record the root and amount union of each number
        int result = 0
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            if( root_table.find(num) == root_table.end() ){
                
            }
            
        }
    }
};