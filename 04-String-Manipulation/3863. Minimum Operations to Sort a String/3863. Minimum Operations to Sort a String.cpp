1class Solution {
2public:
3    int minOperations(string s){
4        char mx = 'a', mn = 'z';
5        int n = s.length();
6        for (int i = 0; i < n; i++){
7            mx = max(mx, s[i]);
8            mn = min(mn, s[i]);
9        }
10        if (ranges::is_sorted(s)){
11            return 0;
12        }
13        if (n == 2){
14            return -1;
15        }
16        if (s[0] == mn || s[n - 1] == mx){
17            return 1;
18        }
19        for (int i = 1; i < n - 1; i++){
20            if (s[i] == mn || s[i] == mx){
21                return 2;
22            }
23        }
24        return 3;
25    }
26};