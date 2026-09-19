1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        int n = nums.size();
5        if (n <= 1) return 0;
6        int jumps = 0;
7        int current_end = 0;
8        int farthest = 0;
9        for (int i = 0; i < n - 1; i++) {
10            farthest = max(farthest, i + nums[i]);
11            if (i == current_end) {
12                jumps++;
13                current_end = farthest;
14                if (current_end >= n - 1) {
15                    break;
16                }
17            }
18        }
19        return jumps;
20    }
21};