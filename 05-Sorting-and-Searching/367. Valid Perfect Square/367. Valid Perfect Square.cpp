class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int l =1;
        long long int r = num;
        while(l<=r){
            long long int mid = l+(r-l)/2;
            long long int sq = mid*mid;
            if(sq==num)
                return true;
            else if(sq<num)
                l = mid+1;
            else 
                r = mid-1;        
        }
        return false;
    }
};
