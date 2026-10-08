1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        string ans;
5        int count = 0;
6        for (char c : s) {
7            if (c == '(') {
8                if (count > 0)
9                    ans += c;
10                count++;
11            } else {
12                count--;
13                if (count > 0)
14                    ans += c;
15            }
16        }
17        return ans;
18    }
19};