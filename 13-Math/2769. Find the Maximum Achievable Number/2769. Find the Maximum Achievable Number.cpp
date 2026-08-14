1class Solution {
2public:
3    int theMaximumAchievableX(int num, int t) {
4        int ans = ((num+t)-1)+(t+1);
5        return ans;
6    }
7};