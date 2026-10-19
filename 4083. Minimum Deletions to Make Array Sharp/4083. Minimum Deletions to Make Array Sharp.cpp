1class Solution {
2public:
3    int minDeletions(vector<int>& nums) {
4        if(nums.empty())
5            return 0;
6        int unique = 1;
7        for(int i=1; i<nums.size(); ++i){
8            if(nums[i]!=nums[i-1])
9                unique++;
10        }
11        return nums.size()-unique;
12    }
13};