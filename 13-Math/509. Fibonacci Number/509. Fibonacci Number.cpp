1class Solution {
2public:
3    int fib(int n) {
4        if (n <= 1) {
5            return n;
6        }
7        int prev2 = 0; 
8        int prev1 = 1; 
9        int current = 0;
10        for (int i = 2; i <= n; ++i) {
11            current = prev1 + prev2;
12            prev2 = prev1;
13            prev1 = current;
14        }
15        return current;
16    }
17};
18