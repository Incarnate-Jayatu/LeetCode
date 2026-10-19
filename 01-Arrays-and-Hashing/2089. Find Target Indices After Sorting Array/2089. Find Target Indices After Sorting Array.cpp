1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6        vector<int> res;
7        for (int i = 0; i < n; ++i) {
8            if (nums[i] == target) {
9                res.push_back(i);
10            }
11        }
12        return res;
13    }
14};