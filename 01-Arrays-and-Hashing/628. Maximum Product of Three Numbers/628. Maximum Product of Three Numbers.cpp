1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6        int m1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
7        int m2 = nums[0] * nums[1] * nums[n - 1];
8        return max(m1, m2);
9    }
10};
11