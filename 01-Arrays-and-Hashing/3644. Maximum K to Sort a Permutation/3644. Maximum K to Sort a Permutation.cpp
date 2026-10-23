1class Solution {
2public:
3    int sortPermutation(vector<int>& nums) {
4        int n = nums.size();
5        int res = INT_MAX;
6        for (int i = 0; i < n; i++) {
7            if (nums[i] == i) {
8                continue;
9            }
10            res &= nums[i];
11        }
12        return res == INT_MAX ? 0 : res;
13    }
14};