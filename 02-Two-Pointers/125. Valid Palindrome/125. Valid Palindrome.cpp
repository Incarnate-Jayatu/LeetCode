1class Solution {
2public:
3    bool isPalindrome(string s) {
4        int l = 0;
5        int r = s.length() - 1;
6        while (l < r) {
7            // Skip non-alphanumeric characters on the left
8            while (l < r && !isalnum(s[l])) {
9                l++;
10            }
11            // Skip non-alphanumeric characters on the right
12            while (l < r && !isalnum(s[r])) {
13                r--;
14            }
15            // Compare lowercase versions of characters
16            if (tolower(s[l]) !=tolower(s[r])) {
17                return false;
18            }
19            l++;
20            r--;
21        }
22        return true;
23    }
24};