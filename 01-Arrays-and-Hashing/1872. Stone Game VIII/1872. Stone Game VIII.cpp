1class Solution {
2public:
3    int stoneGameVIII(vector<int>& stones) {
4        int n = stones.size();
5        for (int i = 1; i < n; ++i) {
6            stones[i] += stones[i - 1];
7        }
8        int max_diff = stones[n - 1];
9        for (int i = n - 2; i >= 1; --i) {
10            max_diff = max(max_diff, stones[i] - max_diff);
11        }
12        return max_diff;
13    }
14};
15