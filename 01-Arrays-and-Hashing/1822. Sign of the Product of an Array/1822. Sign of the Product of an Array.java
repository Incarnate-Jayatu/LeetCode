1class Solution {
2    public int arraySign(int[] nums){
3        int sign = 1;
4        for(int i = 0; i < nums.length; i++){
5            if(nums[i] == 0){
6                return 0;
7            }
8            if(nums[i] < 0){
9                sign = -sign;
10            }
11        }
12        return sign;
13    }
14}
15