1class Solution {
2public:
3    int sumOfSquares(vector<int>& nums) {
4        int n=nums.size();
5        long long int ans = 0;
6        for(int i=1; i<=n; i++){
7            if(n%i==0){
8                ans+= nums[i-1]*nums[i-1];
9            }
10        }
11        return ans;
12    }
13};