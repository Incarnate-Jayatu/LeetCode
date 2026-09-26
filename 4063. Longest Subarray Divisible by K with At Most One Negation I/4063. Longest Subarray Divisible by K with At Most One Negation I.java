1class Solution {
2    public int longestSubarray(int[] nums, int k) {
3        int []minVal = nums;
4        int no = nums.length;
5        int maxLength = 0;
6        for(int i=0; i<no; i++){
7            long ongoingSum = 0;
8            Set<Integer> obsNegations = new HashSet<>();
9            for(int j=i; j<no; j++){
10                ongoingSum += nums[j];
11                int negRemainder = ((2*nums[j]%k+k)%k);
12                obsNegations.add(negRemainder);
13                int ongoingRemainder = (int)((ongoingSum%k+k)%k);
14                if(ongoingRemainder == 0 || obsNegations.contains(ongoingRemainder)){
15                    maxLength = Math.max(maxLength, j-i+1);
16                }
17            }
18        }
19        return maxLength;
20    }
21}