1class Solution { 
2public: 
3    vector<string> generateParenthesis(int n) { 
4        vector<string> ans;
5        string cur;
6        function<void(int,int)> dfs = [&](int open, int close) {
7            if (open == 0 && close == 0) {
8                ans.push_back(cur);
9                return;
10            }
11            if (open > 0) {
12                cur.push_back('(');
13                dfs(open - 1, close);
14                cur.pop_back();
15            }
16            if (close > open) {
17                cur.push_back(')');
18                dfs(open, close - 1);
19                cur.pop_back();
20            }
21        };
22        dfs(n, n);
23        return ans;
24    } 
25};