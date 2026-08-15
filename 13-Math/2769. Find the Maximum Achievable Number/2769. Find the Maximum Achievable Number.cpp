class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        int ans = ((num+t)-1)+(t+1);
        return ans;
    }
};
