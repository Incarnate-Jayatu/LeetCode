1class Solution {
2public:
3    int missingMultiple(std::vector<int>& nums, int k) {
4        std::sort(nums.begin(), nums.end());
5        int current_multiple = k;
6        for (int num : nums) {
7            if (num == current_multiple) {
8                current_multiple += k;
9            }
10        }
11        return current_multiple;
12    }
13};