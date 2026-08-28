1class Solution {
2public:
3    vector<int> sortedSquares(vector<int>& nums) {
4        int n=nums.size();
5        for(int i=0; i<n; i++){
6            nums[i] = nums[i]*nums[i];
7        }
8        sort(nums.begin(), nums.end());
9        return nums;
10    }
11};