1class Solution {
2public:
3    int getSum(int a, int b) {
4        while (b != 0) {
5            unsigned int carry = a & b;
6            a = a ^ b;
7            b = carry << 1;
8        }
9        return a;
10    }
11};