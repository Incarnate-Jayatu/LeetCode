1class Solution {
2public:
3    string mergeAlternately(string word1, string word2) {
4        string word3;
5        int len1 = word1.length();
6        int len2 = word2.length();
7        word3.reserve(len1+len2);
8        int i = 0, j = 0;
9        while (i < len1 && j < len2) {
10            word3.push_back(word1[i++]);
11            word3.push_back(word2[j++]);
12        }
13        if (i < len1) {
14            word3.append(word1.substr(i));
15        }
16        if (j < len2) {
17            word3.append(word2.substr(j));
18        }
19        return word3;
20    }
21};