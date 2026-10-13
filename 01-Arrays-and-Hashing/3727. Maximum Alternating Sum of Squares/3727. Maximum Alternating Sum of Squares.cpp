1class Solution {
2public:
3    long long maxAlternatingSum(vector<int>& nums) {
4        for(auto &it: nums){
5            if(it < 0){
6                it = -it;
7            }
8        }
9        sort(nums.begin(),nums.end());
10        int n = nums.size();
11        int low = 0,high = n-1;
12        long long sol = 0;
13        while(low < high){
14            sol = sol + (1ll * nums[high] * nums[high]) - (1ll * nums[low] * nums[low]);
15            low++;
16            high--;
17        }
18        if(low == high){
19            sol = sol + (1ll * nums[low] * nums[low]);
20        }
21        return sol;
22    }
23};