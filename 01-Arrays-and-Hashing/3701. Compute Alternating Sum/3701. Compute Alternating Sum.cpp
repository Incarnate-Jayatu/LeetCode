1class Solution {
2public:
3    int alternatingSum(vector<int>& nums) {
4        int sum=0;
5        for(int i=0; i<nums.size(); i++){
6            if(i%2==0){
7                sum+=nums[i];
8            }
9            else
10                sum-=nums[i];
11        }
12        return sum;
13    }
14};