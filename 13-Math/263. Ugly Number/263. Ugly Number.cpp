1class Solution {
2public:
3    bool isUgly(int n) {
4        if (n <= 0) return false;
5        for (int factor : {2, 3, 5}) {
6            while (n % factor == 0) {
7                n /= factor;
8            }
9        }
10        return n == 1;
11    }
12};
13