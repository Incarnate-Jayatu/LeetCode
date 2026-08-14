1class Solution {
2public:
3    bool isPalindrome(int x) {
4        if (x < 0 || (x % 10 == 0 && x != 0)) {
5            return false;
6        }
7        int reversedHalf = 0;
8        while (x > reversedHalf) {
9            reversedHalf = reversedHalf * 10 + x % 10;
10            x /= 10;
11        }
12        return x == reversedHalf || x == reversedHalf / 10;
13    }
14};