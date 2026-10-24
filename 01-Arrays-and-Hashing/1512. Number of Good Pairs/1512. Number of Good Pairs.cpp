1class Solution {
2public:
3    int numIdenticalPairs(vector<int>& nums) {
4        int pair=0;
5        for(int i=0; i<nums.size()-1; i++){
6            for(int j=i+1; j<nums.size(); j++){
7                if(nums[i] == nums[j])
8                    pair++;
9            }
10        }
11        return pair;
12    }
13};
14
15