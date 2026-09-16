1class Solution {
2public:
3    bool checkString(string s) {
4        for (int i = 0; i < s.size() - 1; i++) {
5            if (s[i] == 'b' && s[i+1] == 'a') {
6                return false; 
7            }
8        }
9        return true;
10    }
11};
12