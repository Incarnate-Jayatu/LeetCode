1class Solution {
2public:
3    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
4        int n = nums.size(), j = 0;
5        long long cnt = 0;
6        for (int i = 0; i < n; i++) {
7            if (nums[i] < minK || nums[i] > maxK) {
8                j = i + 1;
9                continue;
10            }
11            cnt += (i - j + 1);
12        }
13        return cnt;
14    }
15};