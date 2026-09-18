1class Solution {
2public:
3    string intToRoman(int num) {
4        string Roman = ;
5       vector<pair<int, string>> storeIntRoman = {{1000, M}, {900, CM}, {500, D}, {400, CD}, {100, C}, {90, XC}, {50, L}, {40, XL}, {10, X}, {9, IX}, {5, V}, {4, IV}, {1, I}};
6        for (int i = 0; i < storeIntRoman.size(); i++) {
7            while (num >= storeIntRoman[i].first) {
8                Roman += storeIntRoman[i].second;
9                num -= storeIntRoman[i].first;
10            }
11        }
12        return Roman;
13    }
14};