/*
Author: Tony Hsiao
Date: 2019/05/09
Topic: 
Speed: 12 ms 14.9 MB
Note: 第n個大的ugly number
*/
class Solution {
public:
    int min(int a, int b){
        return (a>b) ? b : a;
    }
    int nthUglyNumber(int n) {
        vector<long long>ans={1};
        int two = 0, three = 0, five = 0, min_ = 1;
        long long prev=1;
        while(n > 1){
            long long a = ans[two] * 2;
            long long b = ans[three] * 3;
            long long c = ans[five] * 5;
            min_ = min(a, min(b, c));
            if(a == min_) two++;
            else if(b == min_) three++;
            else if(c == min_) five++;
            if(prev!=min_){
                n--;
                prev = min_;
                ans.push_back(min_);
            }
        }
        return min_;
    }
};


/* Solution slow, 132 ms 31.9 MB
////////////////////////////
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;

        map<long long, int>ugly_numbers;
        vector<int>factor={2, 3, 5};
        ugly_numbers[1] = 1;

        while(n>1){
            n--;
            long long number = ugly_numbers.begin()->first;
            ugly_numbers.erase(ugly_numbers.begin());
            for(int i=0;i<3;i++){
                // new number doesn't exist
                if(ugly_numbers.find(number * factor[i]) == ugly_numbers.end()) 
                    ugly_numbers[number * factor[i]] = 1;
            }
        }
        return ugly_numbers.begin()->first;
    }
};
*/