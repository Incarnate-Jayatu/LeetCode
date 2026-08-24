1class Solution {
2public:
3    bool checkPowersOfThree(int n) {
4        while (n > 0) {
5            if (n % 3 == 2) {
6                return false;
7            }
8            n /= 3;
9        }
10        return true;
11    }
12};
13