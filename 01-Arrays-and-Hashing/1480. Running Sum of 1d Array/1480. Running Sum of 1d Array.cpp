1class Solution {
2public:
3    vector<int> runningSum(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> result(n, 0); 
6        for (int i = 0; i < n; i++) {
7            for (int j = 0; j <= i; j++) {
8                result[i] += nums[j];
9            }
10        }
11        return result;
12    }
13};
14