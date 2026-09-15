1class Solution {
2public:
3    bool checkPerfectNumber(int num) {
4        if (num <= 1) return false;
5        int sum = 1;
6        for (int i = 2; i * i <= num; i++) {
7            if (num % i == 0) {
8                sum += i;
9                if (i * i != num) {
10                    sum += num / i;
11                }
12            }
13        }
14        return sum == num;
15    }
16};