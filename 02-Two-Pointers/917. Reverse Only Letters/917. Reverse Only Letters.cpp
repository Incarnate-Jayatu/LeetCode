class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            bool isLeftLetter = (s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z');
            bool isRightLetter = (s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z');

            if (!isLeftLetter) {
                left++;
            } 
            else if (!isRightLetter) {
                right--;
            } 
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

/* OPTIMAL SOLUTION
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalpha(s[i])) {
                ++i;
            }
            while (i < j && !isalpha(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
*/
