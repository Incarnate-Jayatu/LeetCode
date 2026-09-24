1class Solution {
2    public int smallestIndex(int[] nums){
3        for(int i = 0; i < nums.length; i++){
4            if(getDigitSum(nums[i]) == i){
5                return i;
6            }
7        }
8        return -1;
9    }
10    private int getDigitSum(int num){
11        int sum = 0;
12        while(num > 0){
13            sum += num % 10;
14            num /= 10;
15        }
16        return sum;
17    }
18}
19