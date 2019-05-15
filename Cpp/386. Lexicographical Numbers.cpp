/*
Author: Tony Hsiao
Date: 2019/05/15
Topic: 386. Lexicographical Numbers
Speed: 68 ms, 11.8MB
Note: 使用字典序去排序1~n的數字
使用排序方式且一個字元一個字元比較會TLE
n=13 => [1,10,11,12,13,2,3,4,5,6,7,8,9]
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int val = 1;
        for(int i=0;i<n;i++){
            ans.push_back(val);
            
            if(val * 10 <= n)
                val = val * 10;
            else if(val + 1 <= n && val + 1 < (val/10+1)*10  ) 
                val = val + 1;
            else{
                val = val / 10 ;
                while(val%10==9)
                    val = val / 10 ;
                val += 1;
            }
            
        }
        return ans;
    }
};