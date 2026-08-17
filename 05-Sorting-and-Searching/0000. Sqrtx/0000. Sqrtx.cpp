1class Solution {
2public:
3    int mySqrt(int x) {
4        if (x == 0 || x == 1) return x;
5        int start = 1;
6        int end = x;
7        int ans = 0;
8        while (start <= end) {
9            int mid = start + (end - start) / 2;
10            if (mid == x / mid) {
11                return mid;
12            } 
13            else if (mid < x / mid) {
14                ans = mid;     
15                start = mid + 1; 
16            } 
17            else {
18                end = mid - 1;   
19            }
20        }
21        return ans;
22    }
23};