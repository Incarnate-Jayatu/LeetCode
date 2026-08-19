1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> res(n, 1);
6        int prefix = 1;
7        int suffix = 1;
8        for (int i = 0; i < n; i++) {
9            res[i] *= prefix;
10            prefix *= nums[i];
11            res[n - 1 - i] *= suffix;
12            suffix *= nums[n - 1 - i];
13        }
14        return res;
15    }
16};
17