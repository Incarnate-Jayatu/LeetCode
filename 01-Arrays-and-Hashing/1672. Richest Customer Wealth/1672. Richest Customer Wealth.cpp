1class Solution {
2public:
3    int maximumWealth(vector<vector<int>>& accounts) {
4        int max=0, sum=0;
5        int m = accounts.size();       // Number of customers (rows)
6        int n = accounts[0].size();    // Number of banks (columns)
7        for(int i=0; i<m; i++){
8            sum=0;
9            for(int j=0; j<n; j++){
10                sum+=accounts[i][j];
11                if(sum > max){
12                    max = sum;
13                }
14            }
15        }
16        return max;
17    }
18};