1class Solution {
2public:
3    int removeElement(std::vector<int>& nums, int val) {
4        int k = 0;
5        for (int i = 0; i < nums.size(); ++i) {
6            if (nums[i] != val) {
7                nums[k] = nums[i];
8                k++;
9            }
10        }
11        return k; 
12    }
13};