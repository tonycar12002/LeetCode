/*
Author: Tony Hsiao
Date: 2019/05/09
Topic: 313. Super Ugly Number
Speed: 72 ms, 10MB
Note:
*/
class Solution {
public:
    int min(int a, int b){
        return (a>b) ? b : a;
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>ans={1};
        vector<int>coeff(primes.size(), 0);
        int cur_nums, index;
        while(n > 1){
            int min_num = INT_MAX;
            for(int i=0;i<primes.size();i++){
                cur_nums = ans[coeff[i]] * primes[i];
                min_num = min(min_num, cur_nums);
                if(min_num == cur_nums)
                    index = i;
            }
            coeff[index] ++;
            if(ans.back()!=min_num){
                n--;
                ans.push_back(min_num);
            }
        }
        return ans.back();
    }
};