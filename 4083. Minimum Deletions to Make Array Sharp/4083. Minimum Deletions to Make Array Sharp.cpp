class Solution {
public:
    int minDeletions(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int unique = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]!=nums[i-1])
                unique++;
        }
        return nums.size()-unique;
    }
};
