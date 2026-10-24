1class Solution {
2public:
3    string convertToBase(int n, int base) {
4        string s = 0123456789;
5        string result = ;
6        while (n > 0) {
7            int rem = n % base;
8            result += s[rem];
9            n /= base;
10        }
11        reverse(result.begin(), result.end());
12        return result;
13    }
14    bool palindrome(string s) {
15        int l = 0;
16        int h = s.length() - 1;
17        while (l <= h) {
18            if (s[l] != s[h]) {
19                return false;
20            }
21            l++;
22            h--;
23        }
24        return true;
25    } 
26    bool isStrictlyPalindromic(int n) {
27        for (int base = 2; base <= n - 2; base++) {
28            string result = convertToBase(n, base);
29            if (!palindrome(result)) return false;
30        }
31        return true;
32    }
33};