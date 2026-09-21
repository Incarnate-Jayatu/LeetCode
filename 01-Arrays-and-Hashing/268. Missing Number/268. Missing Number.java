1class Solution {
2    public int missingNumber(int[] nums) {
3        int n = nums.length;
4        int expectedSum = (n * (n + 1)) / 2;
5        int actualSum = 0;
6        for (int num : nums) {
7            actualSum += num;
8        }
9        return expectedSum - actualSum;
10    }
11}
12