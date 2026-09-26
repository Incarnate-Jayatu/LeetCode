class Solution {
    public int longestSubarray(int[] nums, int k) {
        int []minVal = nums;
        int no = nums.length;
        int maxLength = 0;
        for(int i=0; i<no; i++){
            long ongoingSum = 0;
            Set<Integer> obsNegations = new HashSet<>();
            for(int j=i; j<no; j++){
                ongoingSum += nums[j];
                int negRemainder = ((2*nums[j]%k+k)%k);
                obsNegations.add(negRemainder);
                int ongoingRemainder = (int)((ongoingSum%k+k)%k);
                if(ongoingRemainder == 0 || obsNegations.contains(ongoingRemainder)){
                    maxLength = Math.max(maxLength, j-i+1);
                }
            }
        }
        return maxLength;
    }
}
