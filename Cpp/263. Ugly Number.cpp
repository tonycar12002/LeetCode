/*
Author: Tony Hsiao
Date: 2019/05/09
Topic: 263. Ugly Number
Speed: 0 ms, 8.1 MB
Note: 判斷數字是否為ugly number
*/
class Solution {
public:
    bool isUgly(int num) {
        if( num == 0)
            return false;

        vector<int>factor={2, 3, 5};
        for(int i=0;i<3;i++){
            if(num%factor[i] == 0){
                num /= factor[i];
                i--;
            }
        }
        return (num != 1) ? false : true;
    }
};
