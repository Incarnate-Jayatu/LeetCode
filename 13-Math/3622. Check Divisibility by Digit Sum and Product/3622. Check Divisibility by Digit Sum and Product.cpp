1class Solution {
2public:
3    bool checkDivisibility(int n) {
4        int sum = 0;
5        int product = 1;
6        int temp = n;
7        while (temp > 0) {
8            int digit = temp % 10;
9            sum += digit;
10            product *= digit;
11            temp /= 10;
12        }
13        return (n % (sum + product) == 0);
14    }
15};
16