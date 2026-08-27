1class Solution {
2public:
3     bool containsDuplicate(std::vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        for (size_t i = 1; i < nums.size(); ++i) {
6            if (nums[i] == nums[i - 1]) {
7                return true;
8            }
9        }
10        return false;
11    }
12};