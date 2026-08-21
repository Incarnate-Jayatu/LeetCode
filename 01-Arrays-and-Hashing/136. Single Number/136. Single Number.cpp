1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int ans = 0;
5        for (int num : nums) {
6            ans ^= num;
7        }
8        return ans;
9    }
10};