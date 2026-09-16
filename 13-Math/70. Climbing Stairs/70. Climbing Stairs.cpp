1class Solution {
2public:
3    int climbStairs(int n) {
4        if(n <= 2) return n;
5        int prev2 = 1, prev1 = 2;
6        for(int i = 3; i <= n; i++){
7        int current = prev2 + prev1;
8            prev2 = prev1;
9            prev1 = current;
10        }
11        return prev1;
12    }
13};