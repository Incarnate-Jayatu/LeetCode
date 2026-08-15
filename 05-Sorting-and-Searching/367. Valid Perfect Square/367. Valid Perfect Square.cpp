1class Solution {
2public:
3    bool isPerfectSquare(int num) {
4        long long int l =1;
5        long long int r = num;
6        while(l<=r){
7            long long int mid = l+(r-l)/2;
8            long long int sq = mid*mid;
9            if(sq==num)
10                return true;
11            else if(sq<num)
12                l = mid+1;
13            else 
14                r = mid-1;        
15        }
16        return false;
17    }
18};