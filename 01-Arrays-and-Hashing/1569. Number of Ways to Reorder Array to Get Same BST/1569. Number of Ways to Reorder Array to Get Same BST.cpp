1class Solution {
2public:
3    int numOfWays(vector<int>& nums) {
4        int m = nums.size();
5        // Table of Pascal's triangle
6        table.resize(m + 1);
7        for(int i = 0; i < m + 1; ++i) {
8            table[i] = vector<long long>(i + 1, 1);
9            for(int j = 1; j < i; ++j) {
10                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
11            }
12        }
13        return (dfs(nums) - 1) % mod;
14    }
15private:
16    vector<vector<long long>> table;
17    long long mod = 1e9 + 7;
18    long long dfs(vector<int> &nums){
19        int m = nums.size();
20        if(m < 3) {
21            return 1;
22        }
23        vector<int> leftNodes, rightNodes;
24        for(int i = 1; i < m; ++i){
25            if (nums[i] < nums[0]) {
26                leftNodes.push_back(nums[i]);
27            } else {
28                rightNodes.push_back(nums[i]);
29            }
30        }
31        long long leftWays = dfs(leftNodes) % mod;
32        long long rightWays = dfs(rightNodes) % mod;
33        return (((leftWays * rightWays) % mod) * table[m - 1][leftNodes.size()]) % mod;
34    }
35};