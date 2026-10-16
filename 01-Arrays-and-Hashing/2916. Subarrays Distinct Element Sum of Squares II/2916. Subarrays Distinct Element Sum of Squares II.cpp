1class Solution {
2public:
3    int sumCounts(vector<int>& nums) {
4        const long long MOD = 1e9 + 7;
5        int n = nums.size();
6        vector<long long> cnt(n + 1), tot(n + 1);  // Fenwick trees over previous-copy positions, stored right to left
7        unordered_map<int, int> last;
8        long long ans = 0;
9        for (int r = 0; r < n; r++) {
10            int p = last.count(nums[r]) ? last[nums[r]] : -1;
11            long long c = 0, s = 0;
12            for (int i = n - p - 1; i > 0; i -= i & -i)  // boxes 1..n-p-1 hold the positions > p
13                c += cnt[i], s += tot[i];
14            long long gain = (long long)(r - p) * (r - p) - 2 * (s - p * c);  // at most 1e10
15            ans = (ans + (n - r) * gain) % MOD;
16            for (int i = n - p; i <= n; i += i & -i)  // insert p; p = -1 lands past the end and is skipped
17                cnt[i]++, tot[i] += p;
18            last[nums[r]] = r;
19        }
20        return ans;
21    }
22};