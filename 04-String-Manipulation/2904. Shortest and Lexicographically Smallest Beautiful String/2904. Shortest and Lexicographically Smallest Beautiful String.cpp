class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int bestLeft = -1, minLength = s.length() + 1, ones = 0;
        for (int l = 0, r = 0; r < s.length(); ++r) {
            if (s[r] == '1') ++ones;
            while (ones == k) {
                int currentLen = r - l + 1;
                if (currentLen < minLength || (currentLen == minLength && (bestLeft == -1 || s.compare(l, currentLen, s, bestLeft, minLength) < 0))) {
                    bestLeft = l;
                    minLength = currentLen;
                }
                if (s[l++] == '1') --ones;
            }
        }        return bestLeft == -1 ?  : s.substr(bestLeft, minLength);
    }
};
