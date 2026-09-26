class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        vector<int> dum = source;
        int n=dum.size();
        if(n == 1){
            return dum[0] == target[0];
        }
        long long sourceSum = 0;
        long long targetSum = 0;
        for(int i=0; i<n; i++){
            sourceSum += dum[i];
            targetSum += target[i];
        }
        return sourceSum == targetSum;
    }
};
