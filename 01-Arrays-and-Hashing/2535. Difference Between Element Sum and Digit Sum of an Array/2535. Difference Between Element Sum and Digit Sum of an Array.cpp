1class Solution {
2public:
3    int differenceOfSum(vector<int>& nums) {
4        int s = nums.size();
5        int sume = 0, sumd = 0;
6        for(int i = 0; i < s; i++) {
7            sume += nums[i]; 
8            int temp = nums[i];
9            while (temp > 0) {
10                sumd += temp % 10;
11                temp /= 10;
12            }
13        }
14        return abs(sume - sumd);
15    }
16};
17