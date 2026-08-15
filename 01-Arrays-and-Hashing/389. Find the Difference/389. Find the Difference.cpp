class Solution {
public:
    char findTheDifference(string s, string t) {
        int totalSum = 0;
        for (int i = 0; i < t.length(); i++) {
            totalSum = totalSum + t[i];
        }
        for (int i = 0; i < s.length(); i++) {
            totalSum = totalSum - s[i];
        }
        return (char)totalSum;
    }
};
