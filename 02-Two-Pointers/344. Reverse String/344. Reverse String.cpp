1class Solution {
2public:
3    void reverseString(vector<char>& s) {
4        int r = s.size()-1;
5        int l = 0;
6        while(l<r){
7            int t = s[l];
8            s[l] = s[r];
9            s[r] = t;
10            l++; r--;
11        }    
12    }
13};