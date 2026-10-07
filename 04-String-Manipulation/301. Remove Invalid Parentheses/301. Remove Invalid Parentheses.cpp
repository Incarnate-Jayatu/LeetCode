1class Solution {
2public:
3    vector<string> removeInvalidParentheses(string s){
4        vector<string> ans;
5        remove(s, ans, 0, 0, {'(', ')'});
6        return ans;
7    }
8private:
9    void remove(string s, vector<string>& ans, int i, int j, vector<char> p){
10        int count = 0;
11        for(int k = i; k < s.size(); k++){
12            if(s[k] == p[0]) count++;
13            if(s[k] == p[1]) count--;
14            if(count < 0){
15                for(int x = j; x <= k; x++){
16                    if(s[x] == p[1] && (x == j || s[x - 1] != p[1])){
17                        remove(s.substr(0, x) + s.substr(x + 1), ans, k, x, p);
18                    }
19                }
20                return;
21            }
22        }
23        string rev(s.rbegin(), s.rend());
24        if (p[0] == '(')
25            remove(rev, ans, 0, 0, {')', '('});
26        else
27            ans.push_back(rev);
28    }
29};