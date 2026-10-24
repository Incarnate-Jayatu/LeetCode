1class Solution {
2public:
3    int digitSum(int num) {
4        int sum = 0;
5        while (num > 0) {
6            sum += num % 10;
7            num /= 10;
8        }
9        return sum;
10    }
11    int minElement(vector<int>& nums) {
12        int ans = INT_MAX;
13        for (int num : nums) {
14            ans = min(ans, digitSum(num));
15        }
16        return ans;
17    }
18};