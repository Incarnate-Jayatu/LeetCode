class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int current_multiple = k;
        for (int num : nums) {
            if (num == current_multiple) {
                current_multiple += k;
            }
        }
        return current_multiple;
    }
};
