1class Solution {
2public:
3    int totalMoney(int n) {
4        int totalMoney = 0;
5        int incrementAmt = 0; 
6        int dailyAmt = 1;     
7        for (int i = 1; i <= n; i++) {
8            totalMoney += (dailyAmt + incrementAmt);
9            dailyAmt++;
10            if (i % 7 == 0) {
11                incrementAmt++;
12                dailyAmt = 1;
13            }
14        }
15        return totalMoney;
16    }
17};
18