1class Solution {
2public:
3    int sumCounts(vector<int>& nums) {
4        int n = nums.size(), res = 0;
5        for (int i = 0; i < n; i++) {
6            unordered_set<int> s;
7            for (int j = i; j < n; j++) {
8                s.insert(nums[j]);
9                res += s.size() * s.size();
10            }
11        }
12        return res;
13    }
14};