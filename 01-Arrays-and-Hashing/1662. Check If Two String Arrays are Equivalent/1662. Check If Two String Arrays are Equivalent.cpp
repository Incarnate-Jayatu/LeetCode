1class Solution {
2public:
3    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
4        string s1 = ;
5        string s2 = ;
6        for (const string& s : word1) {
7            s1 += s;
8        }
9        for (const string& s : word2) {
10            s2 += s;
11        }
12        return s1 == s2;
13    }
14};
15