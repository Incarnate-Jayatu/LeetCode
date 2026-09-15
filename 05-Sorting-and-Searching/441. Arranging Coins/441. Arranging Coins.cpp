1class Solution {
2public:
3    int arrangeCoins(int n) {
4        long long left = 1, right = n;
5        int result = 0;
6        while (left <= right) {
7            long long mid = left + (right - left) / 2;
8            long long coinsNeeded = (mid * (mid + 1)) / 2;
9            if (coinsNeeded == n) {
10                return mid;
11            } else if (coinsNeeded < n) {
12                result = mid;
13                left = mid + 1;
14            } else {
15                right = mid - 1;
16            }
17        }
18        return result;
19    }
20};