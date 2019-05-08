/*
Author: Tony Hsiao
Date: 2019/05/08
Topic: 454. 4Sum II
Speed: 148 ms, 28.6 MB
Note: Hash Table
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int>numbers;

        for(int a=0;a<A.size();a++){
            for(int b=0;b<B.size();b++){
                numbers[A[a]+B[b]] += 1;
            }
        }

        int ans = 0;
        for(int c=0;c<C.size();c++){
            for(int d=0;d<D.size();d++){
                auto t = numbers.find(-C[c]-D[d]);
                if(t!=numbers.end()){
                    ans += t->second;
                }
            }
        }

        return ans;
    }
};