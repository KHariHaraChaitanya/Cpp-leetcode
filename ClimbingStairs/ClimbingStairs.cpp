#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> a;
    int climbStairs(int n) {
        a.resize(n+1);
        a[0]=1;
        a[1]=1;
        return calc(n);
    }
    int calc(int n){
        if (n <= 1) return 1;
        if(a[n]==0)
            a[n] = calc(n-1)+calc(n-2);
        return a[n];
    }
};