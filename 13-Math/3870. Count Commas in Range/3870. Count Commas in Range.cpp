1class Solution {
2public:
3    int countCommas(int n) {
4        int ans = 0;
5        for (long long x = 1000; x <= n; x *= 1000) {
6            ans += n - x + 1;
7        }
8        return ans;
9    }
10};