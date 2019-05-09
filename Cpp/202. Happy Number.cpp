/*
Author: Tony Hsiao
Date: 2019/05/09
Topic: 202. Happy Number
Speed: 8ms, 8.5MB
Note:
*/
class Solution {
public:
    bool isHappy(int n) {
        if(n == 0)
            return false;
  
        unordered_map<int, int>record;
        while(n != 1){
            int tmp = n;
            n = 0;
            while(tmp>0){
                n += (tmp%10) * (tmp%10);
                tmp /= 10;
            }
            if(record.find(n) != record.end())
                break;
            record[n] = 1;
            //cout << n << endl;
        }
        return (n != 1) ? false : true;
    }
};