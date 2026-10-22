1class Solution {
2public:
3    int minOperations(vector<int>& nums) {
4        const int n = nums.size();
5        if (n == 1) {
6            return 0;
7        }
8        const int start = find(nums.begin(), nums.end(), 0) - nums.begin();
9        bool asc = true;
10        bool desc = true;
11        for (int i = 1; i < n; i++) {
12            const int value = nums[(start + i) % n];
13            if (value != i) {
14                asc = false;
15            }
16            if (value != n - i) {
17                desc = false;
18            }
19            if (!asc && !desc) {
20                return -1;
21            }
22        }
23        if (asc) {
24            return min(start, n - start + 2);
25        }
26        return min(n - start, start + 2);
27    }
28};