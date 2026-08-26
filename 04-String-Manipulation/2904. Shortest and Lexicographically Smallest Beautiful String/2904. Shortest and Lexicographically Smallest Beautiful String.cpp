1class Solution {
2public:
3    string shortestBeautifulSubstring(string s, int k) {
4        int bestLeft = -1, minLength = s.length() + 1, ones = 0;
5        for (int l = 0, r = 0; r < s.length(); ++r) {
6            if (s[r] == '1') ++ones;
7            while (ones == k) {
8                int currentLen = r - l + 1;
9                if (currentLen < minLength || (currentLen == minLength && (bestLeft == -1 || s.compare(l, currentLen, s, bestLeft, minLength) < 0))) {
10                    bestLeft = l;
11                    minLength = currentLen;
12                }
13                if (s[l++] == '1') --ones;
14            }
15        }
16        return bestLeft == -1 ?  : s.substr(bestLeft, minLength);
17    }
18};
19