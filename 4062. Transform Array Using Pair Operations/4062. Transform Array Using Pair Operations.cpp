1class Solution {
2public:
3    bool canTransform(vector<int>& source, vector<int>& target) {
4        vector<int> dum = source;
5        int n=dum.size();
6        if(n == 1){
7            return dum[0] == target[0];
8        }
9        long long sourceSum = 0;
10        long long targetSum = 0;
11        for(int i=0; i<n; i++){
12            sourceSum += dum[i];
13            targetSum += target[i];
14        }
15        return sourceSum == targetSum;
16    }
17};