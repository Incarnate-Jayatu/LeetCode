1class Solution {
2public:
3    int removeDuplicates(std::vector<int>& nums) {
4        if (nums.empty()) return 0;
5        int j = 0; 
6        for (int i = 1; i < nums.size(); i++) {
7            if (nums[i] != nums[j]) {
8                j++;
9                nums[j] = nums[i]; 
10            }
11        }
12        return j + 1;
13    }
14};