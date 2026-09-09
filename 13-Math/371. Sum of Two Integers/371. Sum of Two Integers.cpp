1class Solution {
2public:
3    int getSum(int a, int b) {
4        
5        while (b != 0) {
6            unsigned int carry = a & b;
7            a = a ^ b;
8            b = carry << 1;
9        }
10
11        return a;
12    }
13};