1class Solution {
2public:
3    string reverseVowels(string s) {
4        int left =0;
5        int right =s.length()-1;
6        while(left<right){
7            while(left<right && !isvowel(s[left])) left++;
8            while(left<right && !isvowel(s[right])) right--;
9            swap(s[left++], s[right--]);
10        }
11        return s;
12    }
13private:
14    bool isvowel(char c){
15        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'; 
16    }    
17};