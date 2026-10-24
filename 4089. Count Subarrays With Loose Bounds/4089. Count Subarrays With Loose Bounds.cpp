class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size(), j = 0;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                j = i + 1;
                continue;
            }
            cnt += (i - j + 1);
        }
        return cnt;
    }
};
