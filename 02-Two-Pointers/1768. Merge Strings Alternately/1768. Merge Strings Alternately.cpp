class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word3;
        int len1 = word1.length();
        int len2 = word2.length();
        word3.reserve(len1+len2);
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            word3.push_back(word1[i++]);
            word3.push_back(word2[j++]);
        }
        if (i < len1) {
            word3.append(word1.substr(i));
        }
        if (j < len2) {
            word3.append(word2.substr(j));
        }
        return word3;
    }
};
