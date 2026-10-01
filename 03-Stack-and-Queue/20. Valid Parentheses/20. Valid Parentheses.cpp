1class Solution{
2public:
3    bool isValid(string s){
4        stack<char> st;
5        for(char ch : s){
6            if(ch == '(' || ch == '[' || ch == '{'){
7                st.push(ch);
8            } else {
9                if (st.empty()){
10                    return false;
11                }
12                char top = st.top();
13                st.pop();
14                if (ch == ')' && top != '('){
15                    return false;
16                }
17                if (ch == ']' && top != '['){
18                    return false;
19                }
20                if (ch == '}' && top != '{'){
21                    return false;
22                }
23            }
24        }
25        return st.empty();
26    }
27};