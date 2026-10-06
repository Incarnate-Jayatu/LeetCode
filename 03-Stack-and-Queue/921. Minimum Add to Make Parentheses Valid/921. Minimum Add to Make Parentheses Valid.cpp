1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4        int open_needed = 0;
5        int close_needed = 0;
6        for (char c : s){
7            if (c == '('){
8                open_needed++;
9            } 
10            else{
11                if (open_needed > 0){
12                    open_needed--;
13                } 
14                else{
15                    close_needed++;
16                }
17            }
18        }
19        return open_needed + close_needed;
20    }
21};