1class Solution {
2public:
3    int smallestEvenMultiple(int n) {
4        int ans;
5        if(n%2 == 0){
6            ans=n;
7        }
8        else{
9            ans=n*2;
10        }
11        return ans;
12    }
13};