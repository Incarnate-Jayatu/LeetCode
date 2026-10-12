1class Solution {
2public:
3    int maxSum(vector<int>& nums, int k) {
4        const int MOD = 1e9 + 7;
5        int n = nums.size();
6        vector<int> cnt(30, 0);
7        for (int x : nums) {
8            for (int b = 0; b < 30; ++b) {
9                if (x & (1 << b)) cnt[b]++;
10            }
11        }
12        vector<long long> a(n, 0);
13        for (int b = 29; b >= 0; --b) {
14            int c = cnt[b];
15            for (int i = 0; i < c; ++i) {
16                a[i] |= (1LL << b);
17            }
18        }
19        long long ans = 0;
20        for (int i = 0; i < k; ++i) {
21            ans = (ans + a[i] * a[i]) % MOD;
22        }
23        return (int)ans;
24    }
25};