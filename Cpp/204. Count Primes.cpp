/*
Author: Tony Hsiao
Date: 2020/04/11
Topic: 204. Count Primes
Speed: 532 ms, 9.1 MB
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
    bool isPrime(int num, vector<int>& cur_prime) {
        for (auto i:cur_prime) {
            if (num % i == 0)
                return false;
            if (i > sqrt(num))
              break;
        }
        cur_prime.push_back(num);
        return true;
    }
    int countPrimes(int n) {
        vector<int> cur_prime;
        int counter = 0;
        for (int i=2; i<n; ++i) {
            if (isPrime(i, cur_prime)) {
                counter++;
            }
        }
        return counter;
    }
};
