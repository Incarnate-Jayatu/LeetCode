1class Solution {
2public:
3    string capitalizeTitle(string title) {
4        int n = title.length();
5        int i = 0;
6        while (i < n) {
7            int j = i; 
8            while (j < n && title[j] != ' ') {
9                title[j] = tolower(static_cast<unsigned char>(title[j]));
10                j++;
11            }            
12            if (j - i > 2) {
13                title[i] = toupper(static_cast<unsigned char>(title[i]));
14            }
15            i = j + 1;
16        }
17        return title;
18    }
19};
20