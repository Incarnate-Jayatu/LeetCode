1class Solution {
2public:
3    vector<int> concatWithReverse(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(2 * n);
6        for (int i = 0; i < n; i++) {
7            ans[i] = nums[i];
8        }
9        for (int i = 0; i < n; i++) {
10            ans[n + i] = nums[n - 1 - i];
11        }
12        return ans;
13    }
14};