1class Solution {
2public:
3    string reverseOnlyLetters(string s) {
4        int left = 0;
5        int right = s.size() - 1;
6
7        while (left < right) {
8            bool isLeftLetter = (s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z');
9            bool isRightLetter = (s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z');
10
11            if (!isLeftLetter) {
12                left++;
13            } 
14            else if (!isRightLetter) {
15                right--;
16            } 
17            else {
18                swap(s[left], s[right]);
19                left++;
20                right--;
21            }
22        }
23        return s;
24    }
25};
26