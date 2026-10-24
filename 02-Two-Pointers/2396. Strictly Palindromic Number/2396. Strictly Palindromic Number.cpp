class Solution {
public:
    string convertToBase(int n, int base) {
        string s = "0123456789";
        string result = "";
        while (n > 0) {
            int rem = n % base;
            result += s[rem];
            n /= base;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    bool palindrome(string s) {
        int l = 0;
        int h = s.length() - 1;
        while (l <= h) {
            if (s[l] != s[h]) {
                return false;
            }
            l++;
            h--;
        }
        return true;
    } 
    bool isStrictlyPalindromic(int n) {
        for (int base = 2; base <= n - 2; base++) {
            string result = convertToBase(n, base);
            if (!palindrome(result)) return false;
        }
        return true;
    }
};
