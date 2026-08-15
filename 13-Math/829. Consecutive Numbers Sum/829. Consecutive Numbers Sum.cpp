1class Solution {
2public:
3    int consecutiveNumbersSum(int n) {
4        int count = 0;
5        for (int i = 1; i * i <= n; i++) {
6            if (n % i == 0) {
7                if (i % 2 != 0) {
8                    count++;
9                }
10                if ((n / i) % 2 != 0 && (n / i) != i) {
11                    count++;
12                }
13            }
14        }
15        return count;
16    }
17};