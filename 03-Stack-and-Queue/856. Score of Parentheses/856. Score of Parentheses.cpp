1class Solution {
2public:
3    int scoreOfParentheses(string s){
4        int score = 0, depth = 0;
5        for(int i = 0; i < s.size(); ++i){
6            if(s[i] == '('){
7                ++depth;
8            } 
9            else{
10                --depth;
11                if(s[i - 1] == '('){
12                    score += 1 << depth;
13                }
14            }
15        }
16        return score;
17    }
18};