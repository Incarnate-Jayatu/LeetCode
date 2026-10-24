1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(n);
6        int leftSum = 0;
7        for (int i = 0; i < n; ++i) {
8            ans[i] = leftSum;
9            leftSum += nums[i];
10        }
11        int rightSum = 0;
12        for (int i = n - 1; i >= 0; --i) {
13            ans[i] = abs(ans[i] - rightSum);
14            rightSum += nums[i];
15        }
16        return ans;
17    }
18};