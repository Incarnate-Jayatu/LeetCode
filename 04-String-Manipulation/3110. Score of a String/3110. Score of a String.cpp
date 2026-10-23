1class Solution {
2public:
3    int scoreOfString(string s) {
4        int score = 0;
5        for (int i = 0; i < s.size() - 1; ++i) {
6            score += abs(s[i] - s[i + 1]);
7        }
8        return score;
9    }
10};