1class Solution {
2public:
3    int numberOfBeams(vector<string>& bank) {
4        int prev = 0, ans = 0;
5        
6        for (string s : bank) {
7            int count = 0;
8            for (char c : s) {
9                if (c == '1') {
10                    count++;
11                }
12            }
13            if (count != 0) {
14                ans += (prev * count);
15                prev = count;
16            }
17        }
18        
19        return ans;
20    }
21};