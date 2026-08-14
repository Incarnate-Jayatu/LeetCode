1class Solution {
2public:
3    char findTheDifference(string s, string t) {
4        int totalSum = 0;
5        for (int i = 0; i < t.length(); i++) {
6            totalSum = totalSum + t[i];
7        }
8        for (int i = 0; i < s.length(); i++) {
9            totalSum = totalSum - s[i];
10        }
11        return (char)totalSum;
12    }
13};
14