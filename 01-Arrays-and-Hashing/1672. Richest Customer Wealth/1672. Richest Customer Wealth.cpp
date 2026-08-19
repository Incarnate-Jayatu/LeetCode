class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max=0, sum=0;
        int m = accounts.size();       // Number of customers (rows)
        int n = accounts[0].size();    // Number of banks (columns)
        for(int i=0; i<m; i++){
            sum=0;
            for(int j=0; j<n; j++){
                sum+=accounts[i][j];
                if(sum > max){
                    max = sum;
                }
            }
        }
        return max;
    }
};
