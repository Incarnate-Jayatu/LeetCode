1#include <string>
2#include <vector>
3
4class Solution {
5public:
6    bool isIsomorphic(std::string s, std::string t) {
7        
8        if (s.length() != t.length()) {
9            return false;
10        }
11        vector<int> mapS(256, 0);
12        vector<int> mapT(256, 0);
13        for (int i = 0; i < s.length(); ++i) {
14            if (mapS[s[i]] != mapT[t[i]]) {
15                return false;
16            }
17            mapS[s[i]] = i + 1;
18            mapT[t[i]] = i + 1;
19        }
20        return true;
21    }
22};
23