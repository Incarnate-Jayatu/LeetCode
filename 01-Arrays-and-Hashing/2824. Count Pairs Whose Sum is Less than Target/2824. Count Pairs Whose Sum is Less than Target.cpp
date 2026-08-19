1class Solution {
2public:
3    int countPairs(vector<int>& nums, int target) {
4        int count=0;
5        for(int i=0; i<nums.size(); i++){
6            int sum =0;
7            for(int j=i+1; j<nums.size(); j++){
8                if(nums[i]+nums[j] < target){
9                    count++;
10                }
11            }
12        }
13        return count;
14    }
15};