1class Solution {
2public:
3    int rob(vector<int>& nums) {
4        int skip = 0; 
5        int rob = 0;  
6        for (int money : nums) {
7
8            int new_rob = skip + money;
9
10            int new_skip = max(skip, rob);
11
12            rob = new_rob;
13            skip = new_skip;
14        }
15        return max(skip, rob);
16    }
17};
18